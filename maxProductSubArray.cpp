void maxProductSubArray(vector<int> nums) {
    vector<int> a;
 
    a.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        a.push_back(nums[i]);
        if (nums[i - 1] == 0) nums[i] = nums[i];
        else {
            nums[i] = nums[i] * nums[i - 1];
        }
       
    }
    cout << endl;
    int max = 0;
    int maxi = 0;
    int maxj = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) { 
            max = nums[i];
            maxi = i;
        }
    }
   
    for (int i = 0; i < maxi; i++) {
        if (nums[i] == 0) maxj = i + 1;
    }
    
    for (int i = maxj; i <= maxi; i++) {
        cout << a[i] << " ";
    }

}
