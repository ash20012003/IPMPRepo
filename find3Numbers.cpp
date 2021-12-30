void find3Numbers(vector<int> a) {
    if (a.size() < 3) {
        cout << "No triplets found";
        return;
    }
    int seq = 0;
    int min = a[0];
    int max = 10000;
    int sec_max = min;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == min) continue;
        else if (a[i] < min) {
            min = a[i];
            continue;
        }
        else if (a[i] < max) {
            max = a[i];
            sec_max = min;
        }
        else if (a[i] > max) {
            cout << "Triplet : " << min << " " << sec_max << " " << a[i] << endl;
            return;
        }
    }
    cout << "No triplets found";
}