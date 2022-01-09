void waterStoreM1(vector<int> nums) {
    int a = 0;
    int b = 0;
    int ans = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > a) a = nums[j];
        }
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > b) b = nums[j];
        }
        ans += (min(a, b) - nums[i]);
    }
    cout << "\nWater stored in method 1 is : " << ans << endl;
}

/*
Create two arrays left and right of size n. create a variable max_ = INT_MIN.
Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign left[i] = max_
Update max_ = INT_MIN.
Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign right[i] = max_
Traverse the array from start to end.
The amount of water that will be stored in this column is min(a,b) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored
Print the total amount of water stored.
*/

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}

/*
Instead of maintaining two arrays of size n for storing the left and a right max of each element, maintain two variables 
to store the maximum till that point. Since water trapped at any element = min(max_left, max_right) – arr[i]. Calculate 
water trapped on smaller elements out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.
*/

int findWater(int arr[], int n)
{
    // initialize output
    int result = 0;
 
    // maximum element on left and right
    int left_max = 0, right_max = 0;
 
    // indices to traverse the array
    int lo = 0, hi = n - 1;
 
    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
 
    return result;
}
