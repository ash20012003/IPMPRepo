#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include <bits/stdc++.h>
#include <cmath>
struct Node *root=NULL;
void Treecreate()
{
 struct Node *p,*t;
 int x;
 struct Queue q;
 create(&q,100);

 printf("Enter root value ");
 scanf("%d",&x);
 root=(struct Node *)malloc(sizeof(struct Node));
 root->data=x;
 root->lchild=root->rchild=NULL;
 enqueue(&q,root);

 while(!isEmpty(q))
 {
 p=dequeue(&q);
 printf("Enter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 enqueue(&q,t);
 }
 printf("Enter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 enqueue(&q,t);
 }
 }
}

int size(struct Node *p){
  if(p==NULL) return 0;
  else return size(p->lchild)+1+size(p->rchild);
}

int height(struct Node *p){
  int x,y;
  if(p==NULL) return 0;
  x=height(p->lchild);
  y=height(p->rchild);
  if(x>y) return x+1;
  else return y+1;
}

int diameter(struct Node *p){
  if(p==NULL) return 0;
  int lheight = height(p->lchild);
  int rheight = height(p->rchild);

  int ldiameter = diameter(p->lchild);
  int rdiameter = diameter(p->rchild);

  return fmax(lheight+rheight+1,fmax(ldiameter,rdiameter));
}

int getWidth(struct Node *p, int level){
  if(p==NULL) return 0;
  if(level==1) return 1;
  return getWidth(p->lchild,level-1) + getWidth(p->rchild,level-1);
}

int getMaxWidth(struct Node *p){
  int maxWidth = 0;
  for(int i=1;i<height(p);i++){
    if(maxWidth<getWidth(p,i)) maxWidth = getWidth(p,i);
  }
  return maxWidth;
}

void Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}
