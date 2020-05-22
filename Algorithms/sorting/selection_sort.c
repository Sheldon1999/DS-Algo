#include<stdio.h>
int main(){
int n,i,min,j,t,I;
printf("enter the size of array:");
scanf("%d",&n);
int A[n];
printf("enter the array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
for(i = 0;i < n;i++){
I = i;
for(j = i + 1;j < n;j++){
if(A[j] < A[I])
I = j;
}
t = A[i];
A[i] = A[I];
A[I] = t;
}
for(i = 0;i < n;i++)
printf("%d ",A[i]);
return 0;
}
