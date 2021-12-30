/*Create a variable sum = 1 which will store the missing number and a counter variable c = 2.
Traverse the array from start to end.
Update the value of sum as sum = sum – array[i] + c and update c as c++.
Print the missing number as a sum.*/

void missingNumber(vector<int> a) {
    int sum = 1, c = 2;
    for (int i = 0; i < a.size(); i++) {
        sum = sum - a[i] + c;
        c++;
    }
    cout << "\n" << sum;
}