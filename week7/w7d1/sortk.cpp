void sortk(int nums[], int k, int n) {
    priority_queue<int, vector<int>, greater<int> > gq(nums,nums+k+1);
    vector<int> ans;
    int index = 0;

    for (int i = k + 1; i < n; i++) {
   //     ans.push_back(gq.top());
        nums[index++] = gq.top();
        gq.pop();
        gq.push(nums[i]);
    }
    while (gq.empty() == false) {
        //ans.push_back(gq.top());
        nums[index++] = gq.top();
        gq.pop();
    }
    for (int j = 0; j < n; j++) cout << nums[j]<<" ";
}

/*
Construct min heap with first k elements
pop the heap and make it the index th element
push the next element of the array into the heap
automatically, heap gets heapified as we are using stl
There will still be some elements in the heap, so keep poping the heap and insert it into the array
*/
