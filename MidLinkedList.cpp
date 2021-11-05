#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
  int A[] = {1,2,3,4,5};
  LinkedList L(A,5);

  L.Display();
  Node *p = L.first;
  
  int i = L.Length();
  
  if(i%2!=0)
  {for(int j=0;j<(i/2);j++)
    p=p->next;
  cout <<"\n"<<p->data;
  }
  else{
    for(int j=0;j<i/2 -1;j++)
     p = p->next;
    float mid = (p->data + (p->next)->data)/2; 
    cout << "\n" << mid;
  }
} 