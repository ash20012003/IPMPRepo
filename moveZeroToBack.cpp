void moveZero(int arr[], int n) {
    int i = 0; int j = n - 1;
    for (i = 0; i < j;i++) {
        if (arr[i] == 0) {
            swap(&arr[i], &arr[j]);
            //i++;
            j--;
        }
        if (arr[j] == 0) j--;
    }
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
 }
