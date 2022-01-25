
class Solution{
public:
    int fact(int n){
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }
    int findSmallerInRight(string str, int low, int high)
{
    int countRight = 0, i;
 
    for (i = low + 1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;
 
    return countRight;
}
 
// A function to find rank of a string in all permutations
// of characters
int rank(string s)
{
    int len = s.size();
    int mul = fact(len);
    int rank = 1;
    int countRight;
 
    int i;
    for (i = 0; i < len; ++i) {
        mul /= len - i;
 
        // count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(s, i, len - 1);
 
        rank += countRight * mul;
    }
 
    return rank;
}
    
};
