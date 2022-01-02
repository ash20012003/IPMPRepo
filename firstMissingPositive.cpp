class Solution {
public:
int firstMissingPositive(vector<int> nums)
{
    int flag = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1) flag = 1; 
    }
    if(flag ==0) return 1;
    else{
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=0 || nums[i]>nums.size()) nums[i] = 1;
    }
    for(int i=0;i<nums.size();i++){
        if(nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
    }
    int j = 0;
    for(j=0;j<nums.size();j++){
        if(nums[j] > 0) return j+1;
    }
    return j+1;}
}
};
