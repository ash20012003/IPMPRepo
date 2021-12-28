void findOddOccurrance(vector<int> a) {
    int x = 0, first = 0, second = 0;
    for (int i = 0; i < a.size(); i++) {
        x ^= a[i];
    }
    int setBit = x & ~(x - 1);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] & setBit) first ^= a[i];
        else second ^= a[i];
    }
    cout << first << " " << second;
}