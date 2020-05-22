#include<stdio.h>
int main(){
int n,i,e;
printf("enter size:");
scanf("%d",&n);
int A[i];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
printf("enter element to be searched:");
scanf("%d",&e);
int I;
I = -1;
for(i = 0;i < n;i++){
if(A[i] == e){
I = 0;
printf("element is at index %d",i);
break;
}
}
if(I == -1)
printf("element is not there....!");
return 0;
}

