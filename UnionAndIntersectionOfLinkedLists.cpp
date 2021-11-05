#include <iostream>
#include "LinkedList.h"
using namespace std;
#include <unordered_map>

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

bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

struct Node* getUnion(
    struct Node* head1,
    struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;
 
    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
}

struct Node* getIntersection(struct Node* head1,
                             struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
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
  Node *a = L1.first;
  Node *b = L2.first;
  Node* p = getUnion(a,b);
  cout <<"\nUnion of the two LinkedList is : ";
  printList(p);
  Node *t = getIntersection(a,b);
  cout <<"\nIntersection of the two LinkedList is : ";
  printList(t);
} 
