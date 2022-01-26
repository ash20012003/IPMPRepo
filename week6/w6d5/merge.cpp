vector<int> merge(vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    while (i != n && j != m) {
        if (a[i] >= b[j]) {
            ans.push_back(b[j]);
            j++;
        }
        if (a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        }
    }
    while (i != n) {
        ans.push_back(a[i]);
        i++;
    }
    while (j != m) {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
