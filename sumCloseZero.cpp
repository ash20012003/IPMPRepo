vector<int> sumCloseZero(vector<int> nums) {
    vector<int> ans;
    int min = INT_MAX;
    int minx = 0, miny = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int sum = nums[i] + nums[j];
            if (abs(sum) < min) { 
                min = abs(sum);
                minx = i;
                miny = j;
            }
        }
    }
    ans.push_back(nums[minx]);
    ans.push_back(nums[miny]);
    return ans;
}

vector<int> sumCloseZeroAlt(vector<int> nums){
  vector<int> ans;
  int minx,miny;
  sort(nums.begin(),nums.end());
  int min = INT_MAX;
  int l = 0;
  int h = nums.size();
  while(l<h){
    int sum = nums[l]+nums[h];
    if(abs(sum) < min){
      min = abs(min);
      minx = l;
      miny = h;
    }
    if(sum > 0) h--;
    if(sum < 0) l++;
  }
  ans.push_back(minx);
  ans.push_back(miny);
  return ans;
}
