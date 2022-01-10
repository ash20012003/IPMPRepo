/*1) Iterate though input array arr[], for every element arr[i], increment arr[arr[i]%k] by k (arr[] becomes {2, 11, 11, 29, 11, 12, 1, 15 })
2) Find the maximum value in the modified array (maximum value is 29). Index of the maximum value is the maximum repeating element (index of 29 is 3).
3) If we want to get the original array back, we can iterate through the array one more time and do arr[i] = arr[i] % k where i varies from 0 to n-1.
How does the above algorithm work? Since we use arr[i]%k as index and add value k at the index arr[i]%k, the index which is equal to maximum repeating 
element will have the maximum value in the end. Note that k is added maximum number of times at the index equal to maximum repeating element and all 
array elements are smaller than k.*/

void maxRepeating(vector<int> nums) {
    int k = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        nums[nums[i] % k] += k;
    }
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) max = nums[i];
    }
    cout << "\n" << max%k << endl;
}
