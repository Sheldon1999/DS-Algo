#include<iostream>
using namespace std;
class node{
public:
int data;
node *link;
};
node *head = NULL;
void insert(){
int a;
cout << "Enter the element:";
cin >> a;
node *temp = new node();
temp->data = a;
temp->link = NULL;
if(head == NULL){
head = temp;
}
else{
node *temp1 = new node();
temp1 = head;
while(temp1->link != NULL){
temp1 = temp1->link;
}
temp1->link = temp;
}
}
void print(){
node *temp1 = new node();
temp1 = head;
while(temp1->link != NULL){
cout << temp1->data;
temp1 = temp1->link;
}
if(temp1->link == NULL)
cout << temp1->data;
}
void del(int n){
node *temp = new node();
temp = head;
if(n == 1){
head = temp->link;
delete temp;
}
else{
for(int i = 1;i < n-1;i++){
temp = temp->link;
}
node *temp1 = new node();
temp1 = temp->link;
temp->link = temp1->link;
delete temp1;
}
}
int main(){
insert();
insert();
insert();
insert();
insert();
insert();
print();
del(6);
print();
return 0;
}



