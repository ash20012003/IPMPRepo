class Solution {
  public:
    // Function to find the number of islands.
   void dfs(vector<vector<char>>&grid,int i,int j,int row,int col){
     if(i<0 || i>=row || j<0 || j>=col || grid[i][j]!='1')
     return;
     
     if(grid[i][j]=='1'){
          grid[i][j]='0';
                   dfs(grid,i+1,j,row,col); 
                   dfs(grid,i-1,j,row,col);
                   dfs(grid,i,j+1,row,col);
                   dfs(grid,i,j-1,row,col);
                   dfs(grid,i+1,j+1,row,col);
                   dfs(grid,i+1,j-1,row,col);
                   dfs(grid,i-1,j-1,row,col);
                   dfs(grid,i-1,j+1,row,col);
     }
 }
   // Function to find the number of islands.
   int numIslands(vector<vector<char>>& grid) {
       // Code here
       int row=grid.size();
       int col=grid[0].size();
       int count=0;
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(grid[i][j]=='1'){
                   grid[i][j]='0';
                   count++;
                   dfs(grid,i+1,j,row,col); 
                   dfs(grid,i-1,j,row,col);
                   dfs(grid,i,j+1,row,col);
                   dfs(grid,i,j-1,row,col);
                   dfs(grid,i+1,j+1,row,col);
                   dfs(grid,i+1,j-1,row,col);
                   dfs(grid,i-1,j-1,row,col);
                   dfs(grid,i-1,j+1,row,col);
               }
           }
       }
       return count;
   }
};
