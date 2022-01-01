bool sumZero(vector<int> a) {
    /*If we consider all prefix sums, we can
notice that there is a subarray with 0
sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.*/
    vector<int> prefixSum;
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        prefixSum.push_back(sum);
    }
    for (int i = 0; i < prefixSum.size(); i++) {
        if (prefixSum[i] == 0) return true;
        for (int j = i + 1; j < prefixSum.size(); j++) {
            if (prefixSum[i] == prefixSum[j]) return true;
        }
    }
    return false;
}