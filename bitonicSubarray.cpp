void bitonicSubarray(vector<int> nums) {
    int max = 0;
    int cleft = 0;
    int cright = 0;
    int i, j, k;
    i = j = k = 0;
    cout << "k" << "     " << "cleft" << "  " << "cright\n";
    for (int k = 1; k < nums.size() - 1; k++) {
        cleft = cright = 0;
        i = j = k;
        while(i > 0) {
            if (nums[i] > nums[i - 1]) {
                cleft += 1;
                i--;
            }
            else i = 0;
        }
        while (j < nums.size()-1) {
            if (nums[j] > nums[j + 1]) {
                cright += 1;
                j++;
            }
            else j = nums.size();
        }
        cout <<k <<"\t" << cleft << "\t" << cright << "\n";
        if (max < cleft + cright) max = cleft + cright;
    }
    cout << "\nMax subarray of the bitonic array is : " << max+1<<"\n";

}

int bitonicSubarrayEffecient(int arr[], int n) 
{ 
    // Length of increasing subarray
    // ending at all indexes 
    int inc[n]; 
    
    // Length of decreasing subarray 
    // starting at all indexes 
    int dec[n]; 
    int i, max; 

    // length of increasing sequence 
    // ending at first index is 1 
    inc[0] = 1; 

    // length of increasing sequence
    // starting at first index is 1 
    dec[n-1] = 1; 

    // Step 1) Construct increasing sequence array 
    for (i = 1; i < n; i++) 
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1; 

    // Step 2) Construct decreasing sequence array 
    for (i = n-2; i >= 0; i--) 
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1; 

    // Step 3) Find the length of
    // maximum length bitonic sequence 
    max = inc[0] + dec[0] - 1; 
    for (i = 1; i < n; i++) 
        if (inc[i] + dec[i] - 1 > max) 
            max = inc[i] + dec[i] - 1; 

    return max; 
} 
