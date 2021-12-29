vector<int> altRepeatingTwoNumbers(vector<int> a) {
    int x = 0;
    int y = 0;
    int s = 0;
    int p = 1;
    int n = a.size() - 2;
    int k = fact(n);
    int l = (n * (n + 1)) / 2;
    for (int i = 0; i < n + 2; i++) {
        s += a[i];
        p *= a[i];
    }
    int sum = s - l;
    int prod = p / k;
    int dif = sqrt(pow((sum), 2) - 4 * prod);
    x = (sum + dif) / 2;
    y = sum - x;
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
/*
* The above question also has an XOR method.
* XOR the given array with another array that has all the elements from 1 to n each occurring only once.
* Then we will be left fit X XOR Y 
* Then follow the same known method by finding setbit to get the values pf X and Y
*/