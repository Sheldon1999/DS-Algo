#include<stdio.h>
int main(){
int n,i,j,f,temp;
printf("enter size:");
scanf("%d",&n);
int A[n];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
for(i = 1;i < n;i++){
f = 0;
for(j = 1;j <= n - i;j++){
if(A[j] < A[j - 1]){
f = 1;
temp = A[j - 1];
A[j - 1] = A[j];
A[j] = temp;
}
}
if(f == 0)
break;
}
for(i = 0;i < n;i++)
printf("%d ",A[i]);
return 0;
}
