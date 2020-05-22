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
temp->link = head;
}
else{
node *temp1 = new node();
temp1 = head;
while(temp1->link != head){
temp1 = temp1->link;
}
temp1->link = temp;
temp->link = head;
}
}
void print(){
node *temp1 = new node();
temp1 = head;
do{
cout << temp1->data;
temp1 = temp1->link;
}while(temp1->link != head);
if(temp1->link == head)
cout << temp1->data;
}
int main(){
insert();
insert();
insert();
insert();
print();
return 0;
}



