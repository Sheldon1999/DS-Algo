#include<stdio.h>
int main(){
int n,i,v,j;
printf("enter size:");
scanf("%d",&n);
int A[n];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
for(i = 1;i < n;i++){
v = A[i];
j = i;
while((j >= 1)&&(A[j - 1] > v)){
A[j] = A[j - 1];
j--;
}
A[j] = v;
}
for(i = 0;i < n;i++)
printf("%d ",A[i]);
return 0;
}
