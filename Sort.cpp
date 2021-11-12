#include <iostream>
using namespace std;

void shellSort(int a[],int n){
  int gap,i,j,temp;
  for(gap=n/2;gap>1;gap/=2){
    for(i=gap;i<n;i++){
      temp = a[i];
      j=i-gap;
      while(j>0 && a[j] > temp){
        a[j+gap] = a[j];
        j=j-gap;
      }
      a[j+gap] = temp;
    }
  }
}

void insertionSort(int a[],int n){
  int j,x;
  for(int i=1;i<n;i++){
    j = i-1;
    x = a[i];
    while(a[j] > x && j>-1)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = x;
  }
}

void bubbleSort(int arr[],int n){

/* we will use flag over here inorder to make the algorithm adoptive. That is sorting an already sorted array takes minimum time.*/

  int flag;
  for(int i=0;i<n-1;i++){
    flag = 0;
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = 1;
      }
    }
    if(flag == 0) break;
  }
}

void selectionSort(int arr[],int n){
  //This algorithm is not adoptive
  //This algorithm is not stable
  int i,j,k;
  for(i=0;i<n-1;i++){
    for(j=k=i;j<n;j++){
      if(arr[j] < arr[k])
        k=j;
      int temp;
      temp = arr[i];
      arr[k] = arr[i];
      arr[i] = temp; 
    }
  }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int findMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 

void countSort(int arr[],int n){
  int max = findMax(arr,n);
  int count[max+1];
  for(int i=0;i<n;i++)
    count[arr[i]] += 1;
  int k=0;
  for(int i=0;i<=max;i++){
    if(count[i] > 0)
      {for(int j=0;j<count[i];j++)
        arr[k++] = i;}
  }
}

void printArray(int a[],int n){
  for(int i=0;i<n;i++)
    cout << a[i] <<" ";
}

int main() {
  int a[] = {1,5,4,2,8,6,3};
  bubbleSort(a, 7);
  printArray(a, 7);
  cout <<endl;
  int b[] = {2,5,3,3,7,8,2,1,5};
  selectionSort(b, 9);
  printArray(b, 9);
} 