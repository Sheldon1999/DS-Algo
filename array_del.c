#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i;
printf("enter size:");
scanf("%d",&n);
int A[n];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
int p;
printf("enter (zero based) position:");
scanf("%d",&p);
for(i = p;i < n;i++)
A[i] = A[i+1];
printf("array after deletion:");
for(i = 0;i < n - 1;i++)
printf("%d ",A[i]);
return 0;
}
