bool isAnagram(string a, string b) {
    map<char, int> m1;
    map<char, int> m2;
    for (int i = 0; i < a.size(); i++) {
        m1[a[i]] += 1;
    }
    for (int i = 0; i < b.size(); i++) {
        m2[b[i]] += 1;
    }
    int flag = 0;
    for (auto& x : m1) {
        for (auto& y : m2) {
            if (x.first == y.first && x.second != y.second) flag = 1;
        }
    }
    if (flag == 0) return true;
    else return false;

}
