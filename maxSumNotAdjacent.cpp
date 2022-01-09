void maxSumNotAdjacent(vector<int> nums) {
    int excl = 0;
    int incl = nums[0];
    int excltemp = 0;
    int incltemp = 0;
    for (int i = 0; i < nums.size(); i++) {
        excltemp = max(excl, incl);
        incltemp = excl + nums[i];
        excl = excltemp;
        incl = incltemp;
    }
    cout << max(excl, incl);
}
