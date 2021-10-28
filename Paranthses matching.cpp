#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
int main() {
  stack<char> s;
  string str;
  cin >> str;
  int l = str.size();
  for(int i=0;str[i]!='\0';i++){
    if(str[i]=='(' || str[i]=='{' || str[i]=='[') s.push(str[i]);
    else if(str[i]==')' || str[i]=='}' || str[i]==']'){
      if(s.empty()) {cout << "NO"; return 0;}
      else s.pop();
    }
  }
  if(s.empty()) cout << "YES";
  else cout << "NO";
}