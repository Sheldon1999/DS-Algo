#include<iostream>
using namespace std;
class node{
public:
int data;
node *link;
};
node *top = NULL;
void push(int a){
node *temp = new node();
temp->data = a;
temp->link = NULL;
if(top == NULL){
top = temp;
}
else{
temp->link = top;
top = temp;
}
}
void pop(){
if(top == NULL)
cout << "stack underflow" << "\n";
else{
node *temp = top;
top = top->link;
delete temp;
}
}
void print(node *p){
if(p->link == NULL){
cout << p->data;
return;
}
cout << p->data;
print(p->link);
}
int main(){
pop();
push(1);
push(2);
push(3);
push(4);
push(5);
print(top);
cout << "\n";
pop();
pop();
pop();
print(top);
return 0;
}


