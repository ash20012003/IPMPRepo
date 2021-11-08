#include <iostream>
using namespace std;

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

void printArray(int a[],int n){
  for(int i=0;i<n;i++)
    cout << a[i] <<" ";
}

int main() {
  int a[] = {1,5,4,2,8,6,3};
  bubbleSort(a, 7);
  printArray(a, 7);
} 