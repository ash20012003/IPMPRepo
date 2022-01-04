vector<int> rearrange(vector<int> a){
  int i = -1;
  for(int j = 0;j<a.size();j++){
    if(a[j]<0)
    {
      i++;
      swap(&a[j],&a[i]);
    }
  }
  int pos = i+1, neg = 0;
  while(pos < a.size() && neg < pos && a[neg]<0){
    swap(&a[pos],a[neg]);
    pos+=1;
    neg+=2;
  }
}
