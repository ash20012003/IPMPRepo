#include <iostream>
#include "LinkedList.h"
using namespace std;
#include <stack>

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node
        = (struct Node*)malloc(
            sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}


void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
  int A[] = {1,2,3,4,5,6};
  int B[] = {9,8,7,6};
  LinkedList L1(A,6);
  LinkedList L2(B,4);
  cout <<"First LinkedList : ";
  L1.Display();
  cout <<"\nSecond LinkedList : ";
  L2.Display();
  
  LinkedList result;
  
  stack<int> s1,s2;
  struct Node *l1;
  
  l1 = L1.first;
  struct Node *l2;
  l2 = L2.first;
  
  while(l1!=NULL){
    s1.push(l1->data);
    l1 = l1->next;
  }
  
  while(l2!=NULL){
    s2.push(l2->data);
    l2 = l2->next;
  }
  
  int carry = 0;

  while(s1.empty()==false || s2.empty()==false){
    int a=0,b=0;
    if(s1.empty()==false){
      a=s1.top();s1.pop();
    }
    if(s2.empty()==false){
      b=s2.top();s2.pop();
    }
    int total=a+b+carry;
    if(total>10) {total = total%10; carry = 1;}
    else{carry = 0;}
    
    result.Insert(0, total);
  }
  cout <<"\nSum of the two linked list is : ";
result.Display();
} 