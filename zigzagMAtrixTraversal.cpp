 int m = 4; int n = 4;
    int arr[4][4] = { {1 ,2 ,3 ,4 },
                      {5 ,6 ,7 ,8 },
                      {9 ,10,11,12},
                      {13,14,15,16} };
    for (int i = 0; i < m; i++) {
        int j = 0, k = i;
        while (j != i + 1 && k != -1 && j!=n) {
            cout << arr[k][j] << " ";
            j++;
            k--;
        }
        cout << endl;
    }
    int j = 1;
    for (int i = m; i < m + n - 1; i++) {
        
            int k = i - j, l = j;
            while (l != n) {
                cout << arr[k][l] << " ";
                k--;
                l++;
            }
            j++;
            cout << endl;
        
    }
