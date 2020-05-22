#include <iostream>
#include<malloc.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* Root = NULL;

void insert_node(int a){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->left = NULL;
	temp->right = NULL;

	int n = 0;
	if(Root == NULL){
		Root = temp;
	}
	
	else{
		struct node* point = Root;
		while(1){
			if(temp->data <= point->data){
				if(point->left != NULL)
					point = point->left;
				else
					break;
			}
			else{
				if(point->right != NULL)
					point = point->right;
				else
					break;
			}
			n++;
		}

		if(temp->data <= point->data)
			point->left = temp;
		else
			point->right = temp;
	}

	cout << "value entered at " << n << "-level." << endl;
}

void preorder(struct node* root){
	if(root){
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root){
	if(root){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(struct node* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
	
int main() {
	int n,t;
	cout << "enter no of values to be inserted:";
	cin >> t;
	while(t--){
		cin >> n;
		insert_node(n);
	}
	
	cout << "preorder:";
	preorder(Root);
	cout << "\ninorder:";
	inorder(Root);
	cout << "\npostorder:";
	postorder(Root);
	return 0;
}

