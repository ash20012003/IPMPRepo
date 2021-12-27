METHOD 1: (Repetition in either of the arrays is not considered)

vector<int> Union(vector<int> a,vector<int> b) {
    vector<int> c;
    int i = 0; int j = 0;
    while (i != a.size() && j != b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i += 1;
        }
        else if (a[i] > b[j]) {
            c.push_back(b[j]);
            j += 1;
        }
        else {
            c.push_back(b[j]);
            i += 1;
            j += 1;
        }
    }
    int n = c.size();
    while (i != a.size()) {
        if (a[i] != c[n - 1]) {
            c.push_back(a[i]);
            
        }
        i += 1;
    }
    while (j != b.size()) {
        if (b[j] != c[n - 1]) {
            c.push_back(b[j]);

        }
        j += 1;
    }
    return c;
}

METHOD 2:(Repetition in either of the arrays is considered)

vector<int> Union(vector<int> a,vector<int> b) {
    vector<int> c;
    unordered_map<int, int> map;
    int i = 0; int j = 0;
    while (i != a.size() && j != b.size()) {
        if (a[i] < b[j]) {
            if (map[a[i]] == 0) {
                map[a[i]] = 1;
                c.push_back(a[i]);
            }
            i += 1;
        }
        else if (a[i] > b[j]) {
            if (map[b[j]] == 0) {
                map[b[j]] = 1;
                c.push_back(b[j]);
            }
            j += 1;
        }
        else {
            if (map[a[i]] == 0)
            {
                map[a[i]] = 1;
                c.push_back(a[i]);
            }
            i += 1;
            j += 1;
        }
    }
    int n = c.size();
    while (i != a.size()) {
        if (a[i] != c[n - 1]) {
            c.push_back(a[i]);
            
        }
        i += 1;
    }
    while (j != b.size()) {
        if (b[j] != c[n - 1]) {
            c.push_back(b[j]);

        }
        j += 1;
    }
    return c;
}