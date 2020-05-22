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
void insert(int d,int p){
node *temp = new node();
temp->data = d;
temp->beg = NULL;
temp->end = NULL;
if(p == 1){
temp->end = head;
head = temp;
}
else{
node *temp1 = new node();
temp1 = head;
for(int i = 1;i < p-1;i++){
temp1 = temp1->end;
}
temp->end = temp1->end;
(temp1->end)->beg = temp;
temp->beg = temp1;
temp1->end = temp;
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
insert(90,1);
insert(67,5);
print();
return 0;
}


