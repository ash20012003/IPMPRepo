string encode(string src)
{     
  //Your code here
  string ans;
  int i=1;
  for(int k=0;k<src.size();k++){
      if(src[k]==src[k+1]) i+=1;
      if(src[k]!=src[k+1]){
      ans+=src[k];
      ans+=std::to_string(i);
      i=1;
  }
      
  }
  return ans;
}  
