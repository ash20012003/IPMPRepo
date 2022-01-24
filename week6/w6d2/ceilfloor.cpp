int ceilFloor(vector<int> nums, int x) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
        if (nums[mid] == x) {
            cout << x << " " << x;
            return mid;
        }
        mid = (right + left) / 2;
        if (nums[mid] <= x) left = mid + 1;
        else right = mid - 1;
    }
    cout << nums[right] << " " << nums[left];
    return 0;
}
