// Given an array of positive integers. All numbers occur an even number of times except one number which occurs an odd number of times. 
// Find the number in O(n) time & constant space.

#include <bits/stdc++.h>
using namespace std;
 

int getOddOccurrence(int arr[],int size)
{
     
    
    unordered_map<int, int> hash;
 
    
    for(int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    
    for(auto i : hash)
    {
        if(i.second % 2 != 0)
        {
            return i.first;
        }
    }
    return -1;
}
 

int main()
{
    int arr[] = { 2, 3, 5, 4, 5, 2, 4,
                    3, 5, 2, 4, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    cout << getOddOccurrence(arr, n);
 
    return 0;
}
 