void longestSumSubArray(vector<int> nums) {
    int maxSum = 0;
    int curSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        curSum += nums[i];
        if (curSum > maxSum) maxSum = curSum;
        if (curSum < 0) curSum = 0;
    }
    cout <<"Max Sum subarray has the sum of : " << max << endl;
}
