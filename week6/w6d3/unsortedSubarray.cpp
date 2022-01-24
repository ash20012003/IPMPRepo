class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    int i = 0;
	    int j = n-1;
	    for(i = 0;i<n;i++){
	        if(arr[i+1]<arr[i]) break;
	    }
	    for(j=n-1;j>=0;j--){
	        if(arr[j-1]>arr[j]) break;
	    }
	   int max = arr[i]; int min = arr[i];
for(int k = i + 1; k <= j; k++)
{
    if(arr[k] > max)
    max = arr[k];
    if(arr[k] < min)
    min = arr[k];
}
 
// step 2(b) of above algo
for(int k = 0; k < i; k++)
{
    if(arr[k] > min)
    {
    i= k;
    break;
    }    
}
 
// step 2(c) of above algo
for( int k = n -1; k >= j+1; k--)
{
    if(arr[k] < max)
    {
    j= k;
    break;
    }
}
	    vector<int> ans;
	    ans.push_back(i);
	    ans.push_back(j);
	    return ans;
	}
};
