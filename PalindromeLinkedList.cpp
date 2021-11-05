#include <iostream>
#include "LinkedList.h"
using namespace std;
#include <stack>

int A[] = {1,2,3,4,5};
LinkedList L(A,5);

bool isPalindrome(){
  Node *t = L.first;
  stack<int> s;
  while(t!=NULL){
    s.push(t->data);
    t = t->next;
  }
  t = L.first;
  int c=0;
  while(t!=NULL){
    if(t->data == s.top()){
      c+=1;
      t = t->next;
      s.pop();
    }
  }
  if(c==L.Length())
    return true;
  else
    return false;
}

int main() {
  
  if(isPalindrome())
    cout <<"Linked List is a Palindrome";
  else
    cout <<"Linked List is not a palindrome";
} 