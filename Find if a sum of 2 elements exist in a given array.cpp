#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <bits/stdc++.h>

int checkIfPairExistsn2compx(int arr[] , int n, int x){
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]+arr[j]==x){cout << "Pair Exists\n"; return 0;}
    }
  }
  cout << "Pair doesnt exist\n";
  return 0;
}

void checkIfPAirExistsncompx(int arr[], int n, int x){
  bool binMap[100] = {0};
  for(int i=0;i<n;i++){
    int temp = x - arr[i];
    if(temp >=0 && binMap[i] == 1) cout << "Pair Present";
  }
  cout <<"Pair Absent";
}

/*
Another method:
-> sort the array
-> add first and last element
-> if sum > x then move pointer on last variable left
-> if sum = x show out put
-> if sum < x then move pointer on first variable right
-> if no conditions satisfies then print failure output
*/