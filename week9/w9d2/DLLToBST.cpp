/* MY CODE */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

struct DLL {
	int data;
	DLL *left, *right;
};

node* generateBST(DLL *I, int low, int high){
	node *root = new node();
	if(low < high){
	int mid = (low+high)/2;
	DLL *temp = I;
	for(int i = 1; i<=mid;i++){
		temp = temp->right;
	}
	
	root->data = temp->data;
	root->left = generateBST(I,0,mid);
	root->right = generateBST(I,mid+1,high);
}
	return root;
}


/* OR */


int countNodes(Node *head);
 
Node* sortedListToBSTRecur(Node **head_ref, int n);
 
/* This function counts the number of
nodes in Linked List and then calls
sortedListToBSTRecur() to construct BST */
Node* sortedListToBST(Node *head)
{
    /*Count the number of nodes in Linked List */
    int n = countNodes(head);
 
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}
 
/* The main function that constructs
balanced BST and returns root of it.
head_ref --> Pointer to pointer to
head node of Doubly linked list
n --> No. of nodes in the Doubly Linked List */
Node* sortedListToBSTRecur(Node **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    Node *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* head_ref now refers to middle node,
    make middle node as root of BST*/
    Node *root = *head_ref;
 
    // Set pointer to left subtree
    root->prev = left;
 
    /* Change head pointer of Linked List
    for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right
    subtree and link it with root
    The number of nodes in right subtree
    is total nodes - nodes in
    left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}
 
/* UTILITY FUNCTIONS */
/* A utility function that returns
count of nodes in a given Linked List */
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
/* Function to insert a node at
the beginning of the Doubly Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* since we are adding at the beginning,
    prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if((*head_ref) != NULL)
    (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
