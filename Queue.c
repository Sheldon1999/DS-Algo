#include <stdio.h>
#define max_size 101
int A[max_size];
int front = -1;
int rear = -1;
void EnQueue(int a){
if(rear == max_size-1)
printf("error:Queue overflow\n");
else if(front == -1&&rear == -1)
{front++;
rear++;}
else
rear++;
A[rear] = a;
}
void DeQueue(){
if(front == -1)
printf("error:Queue underflow\n");
else if(front == rear)
{front = -1;
rear =-1;
}
else
front++;
}
void print(){
int i;
printf("Queue is:");
for(i=front;i<=rear;i++)
printf("%d ",A[i]);
printf("\n");
}
int main()
{
   EnQueue(1);
   EnQueue(2);
   EnQueue(3);print();
   DeQueue();print();
   DeQueue();print();
   return 0;
}
