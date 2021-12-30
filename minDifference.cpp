void maxDif(vector<int> a) {
    int dif = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] - a[i] > dif) dif = a[j] - a[i];
        }
    }
    cout << dif;
}

void altMaxDif(vector<int> a) {
    int min = a[0];
    int dif = a[1] - a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - min > dif) dif = a[i] - min;
        if (a[i] < min) min = a[i];
    }
    cout << "\n" << dif;
}