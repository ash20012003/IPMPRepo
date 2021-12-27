vector<int> Intersection(vector<int> a, vector<int> b) {
    vector<int> c;
    unordered_map<int, int> map;
    int i = 0; int j = 0;
    while (i != a.size() && j != b.size()) {
        if (a[i] < b[j]) i += 1;
        else if (a[i] > b[j]) j += 1;
        else {
            if (map[a[i]] == 0) {
                map[a[i]] = 1;
                c.push_back(a[i]);
            }
            i += 1;
            j += 1;
        }
    }
    return c;
}