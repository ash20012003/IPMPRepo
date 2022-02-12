class Solution {
public:
    
    vector<int> ans;
    
    vector<int> slicing(vector<int>& arr,int X, int Y)
    {
 
    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
 
    // To store the sliced vector
    vector<int> result(Y - X + 1);
 
    // Copy vector using copy function()
    copy(start, end, result.begin());
 
    // Return the final sliced vector
    return result;
    }
    
    
    vector<int> sortedArrayToBST(vector<int> nums) {
        // Code here
        int low = 0;
        int high = nums.size();
        if(low<high){
        int mid = (low+high)/2;
        ans.push_back(nums[mid]);
        vector<int> v1 = slicing(nums,0,mid-1);
        vector<int> v2 = slicing(nums,mid+1,high-1);
        sortedArrayToBST(v1);
        sortedArrayToBST(v2);
        }
        return ans;
    }
};
