#include <iostream>
#include "LinkedList.h"
using namespace std;
#include <unordered_map>

int main() {
  int A[] = {1,2,3,4,5,6};
  int B[] = {9,8,7,6};
  LinkedList L1(A,6);
  LinkedList L2(B,4);
  L1.Display();
  cout <<endl;
  L2.Display();
  
  unordered_map<int,int> m;
  
  Node *a = L1.first;
  
  while(a!=NULL){
    m[a->data] = 1; 
    a = a->next;
  }
  Node *b = L2.first;
  while(b!=NULL){
    if(m[b->data] > 1){
      cout << "Intersection point : "<<b->data<<endl;
      b = b->next;
    }
  }
}