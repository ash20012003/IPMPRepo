void majorityElement(vector<int> nums,int x) {
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        if (nums[i] < x) i++;
        if (nums[j] > x) j--;
    }
    int n = nums.size();
    if (j - i >= n / 2) cout << "Majority";
    else cout << "Not Majority";
}

void majorityElementAlt(vector<int> nums, int x) {
    int mid = nums.size() / 2;
    if (nums[mid] == x) cout << "Majority";
    else cout << "Not Majority";
}
