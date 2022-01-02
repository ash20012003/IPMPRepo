void middleSum(vector<int> nums) {
    int mid;
    int l = 0;
    int h = nums.size() - 1;
    while (l<h) {
        if (nums[l] < nums[h]) { 
            l++;
            nums[l] = nums[l] + nums[l - 1];
        }
        else if (nums[l] > nums[h]) { 
            h--;
            nums[h] = nums[h] + nums[h + 1];
        }
        else if (nums[l] == nums[h]) {
                
                l++;
                h--;
                mid = nums[l];
                nums[l] = nums[l] + nums[l - 1];
                nums[h] = nums[h] + nums[h + 1];
            
        }
    }
    cout << mid;
}
