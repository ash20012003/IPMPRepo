void subarraySumBruteForce(int arr[], int n, int s)
{
    // Your code here
   
    int i = 0; int j = 0; int flag = 0;
    for (i = 0; i < n; i++) {
        int sum = arr[i];
        for (j = i - 1; j > 0; j--) {
            sum += arr[j];

            if (sum == s) {
                cout << j+1 << " " << i+1<<"\n";
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
}

int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of 
    first element and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and 
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}
