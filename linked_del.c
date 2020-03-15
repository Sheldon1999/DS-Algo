#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *link;
}*head = NULL;
void insert(){
struct node *temp = (struct node*)malloc(sizeof(struct node));
printf("Enter the element:");
scanf("%d",&temp->data);
temp->link = NULL;
if(head == NULL){
head = temp;
}
else{
struct node *temp1;
temp1 = head;
while(temp1->link != NULL){
temp1 = temp1->link;
}
temp1->link = temp;
}
}
void print(){
struct node *temp1;
temp1 = head;
while(temp1->link != NULL){
printf("%d ",temp1->data);
temp1 = temp1->link;
}
if(temp1->link == NULL)
printf("%d",temp1->data);
}
void del(int n){
int i;
struct node *temp;
temp = head;
if(n == 1){
head = temp->link;
delete temp;
}
else{
for(i = 1;i < n-1;i++){
temp = temp->link;
}
struct node *temp1;
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
printf("Linked list before deletion:");
print();
printf("\nLinked list after deletion:");
del(6);
print();
return 0;
}
