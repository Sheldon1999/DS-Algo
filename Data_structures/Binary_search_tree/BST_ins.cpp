#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
int data;
struct node *left;
struct node *right;
}* root = NULL;
struct node* insert(struct node *root,int a){
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->data = a;
temp->left = NULL;
temp->right = NULL;
if(root == NULL){
root = temp;
}
else if(a <= root->data){
insert(root->left,a);
}
else{
insert(root->right,a);
}
return root;
}
int main(){
root = insert(root,5);
root = insert(root,4);
root = insert(root,6);
root = insert(root,2);
root = insert(root,8);
root = insert(root,3);
root = insert(root,7);
root = insert(root,1);
root = insert(root,9);
root = insert(root,10);
return 0;
}
