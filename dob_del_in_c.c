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
void del(int p){
struct node *temp1;
temp1 = head;
if(p == 1){
head = temp1->end;
free(temp1);
}
else{
for(int i = 1;i <= p-1;i++){
temp1 = temp1->end;
}
if(temp1->end == NULL)
(temp1->beg)->end = NULL;
else{
(temp1->beg)->end = temp1->end;
(temp1->end)->beg = temp1->beg;
}
free(temp1);
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
insert();
print();
del(5);
print();
del(2);
print();
return 0;
}


