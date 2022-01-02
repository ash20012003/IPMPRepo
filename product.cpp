vector<int> product(vector<int> nums) {

    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        ans1.push_back(1);
        ans2.push_back(1);
    }
    for (int i = 1; i < nums.size(); i++) {
        
        ans1[i] = ans1[i - 1] * nums[i-1];
        
    }
    for (int i = nums.size()-2; i >=0; i--) {
     
        ans2[i] = ans2[i + 1] *nums[i+1];
      
    }
    for (int i = 0; i < nums.size(); i++) {
        ans[i] = ans1[i] * ans2[i];
    }
    return ans;
}
