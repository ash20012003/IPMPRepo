class Solution {
public:
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    vector<int> nextPermutation(vector<int>& nums) {
    int index = 0;
    int flag = 0;
    if(nums.size()==0 || nums.size()==1) return nums;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        sort(nums.begin(),nums.end());
        return nums;
    }
    for (int i = nums.size() - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
            swap(&nums[i], &nums[index]);
            break;
        }
    }
    int low = index + 1;
    int high = nums.size() - 1;
    while (low < high) {
        swap(&nums[low], &nums[high]);
        low++;
        high--;
    }
    return nums;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                int temp = nums[i], index=i; 
                for(int j = i+1; j<n; j++){
                    if(nums[j]<temp && nums[j]>nums[i-1]){
                        temp = nums[j];
                        index = j;
                    }
                }
                swap(nums[i-1],nums[index]);
                sort(nums.begin() + i,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};
