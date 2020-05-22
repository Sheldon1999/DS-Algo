#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i;
printf("enter size:");
scanf("%d",&n);
int A[n + 1];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
int e,p;
printf("enter element and (zero based) position:");
scanf("%d %d",&e,&p);
for(i = n;i > p;i--)
A[i] = A[i - 1];
A[p] = e;
printf("array after insertion:");
for(i = 0;i <= n;i++)
printf("%d ",A[i]);
return 0;
}
