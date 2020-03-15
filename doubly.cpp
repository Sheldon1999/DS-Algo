#include<iostream>
using namespace std;
class node{
public:
int data;
node *beg;
node *end;
};
node *head = NULL;
void insert(){
int a;
cout << "Enter the element:";
cin >> a;
node *temp = new node();
temp->data = a;
temp->beg = NULL;
temp->end = NULL;
if(head == NULL){
head = temp;
}
else{
node *temp1 = new node();
temp1 = head;
while(temp1->end != NULL){
temp1 = temp1->end;
}
temp1->end = temp;
temp->beg = temp1;
}
}
void print(){
node *temp1 = new node();
temp1 = head;
while(temp1->end != NULL){
cout << temp1->data;
temp1 = temp1->end;
}
if(temp1->end == NULL)
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


