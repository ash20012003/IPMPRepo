#include <iostream>
#include "LinkedList.h"
using namespace std;

void display(struct Node *p){
  if(p!=NULL){
    display(p->next);
    cout << " "<<p->data;
  }
}

int main() {
  int A[] = {1,2,3,4,5};
  LinkedList L(A,5);

  Node *t = L.first;
  display(t);
} 