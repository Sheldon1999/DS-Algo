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
void print(){
struct node *temp2;
temp2 = head;
while(temp2->end != NULL){
printf("%d",temp2->data);
temp2 = temp2->end;
}
if(temp2->end == NULL)
printf("%d",temp2->data);
}
int main(){
insert();
insert();
insert();
insert();
print();
return 0;
}

