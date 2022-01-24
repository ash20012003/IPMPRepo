int fixedPoint(int arr[], int low, int high)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (mid == arr[mid])
            return mid;
        int res = -1;
        if (mid + 1 <= arr[high])
            res = fixedPoint(arr, (mid + 1), high);
        if (res != -1)
            return res;
        if (mid - 1 >= arr[low])
            return fixedPoint(arr, low, (mid - 1));
    }
 
    /* Return -1 if there is no Fixed Point */
    return -1;
}
