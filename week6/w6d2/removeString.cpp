class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        int flag = 0;
        string string3;
        for(int i=0;i<string1.size();i++){
            flag = 0;
            for(int j=0;j<string2.size();j++){
                if(string1[i] == string2[j]) flag = 1;   
            }
            if(flag==0) string3+=string1[i];
        }
        return string3;
    }
};
