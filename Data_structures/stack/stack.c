#include <stdio.h>
#define max_size 101
int A[max_size];
int top = -1;
void push(int a){
if(top == max_size-1)
printf("error:stack overflow\n");
else
top++;
A[top] = a;
}
void pop(){
if(top == -1)
printf("error:stack underflow\n");
else
top--;
}
void print(){
int i;
printf("stack is:");
for(i=0;i<=top;i++)
printf("%d ",A[i]);
printf("\n");
}
int main()
{
   push(1);
   push(2);
   push(3);print();
   pop();print();
   pop();print();
   return 0;
}
