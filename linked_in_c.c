#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *link;
}*head = NULL;
void insert(){
struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));
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
int main(){
insert();
insert();
insert();
insert();
print();
return 0;
}
