#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *beg;
struct node *end;
}*head = NULL;
void insert(){
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
printf("Enter the element:");
scanf("%d",&temp->data);
temp->beg = NULL;
temp->end = NULL;
if(head == NULL){
head = temp;
}
else{
struct node *temp1;
temp1 = head;
while(temp1->end != NULL){
temp1 = temp1->end;
}
temp1->end = temp;
temp->beg = temp1;
}
}
void insert(int d,int p){
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
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
struct node *temp1;
temp1 = head;
while(temp1->end != NULL){
printf("%d,",temp1->data);
temp1 = temp1->end;
}
if(temp1->end == NULL)
printf("%d\n",temp1->data);
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


