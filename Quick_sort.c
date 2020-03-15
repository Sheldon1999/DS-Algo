#include<stdio.h>
int partition(int *A,int p,int r){
int x = A[r],j = p - 1,i;
for(i = p;i < r;i++){
if(A[i] <= x){
j++;
int t = A[i];
A[i] = A[j];
A[j] = t;
}
}
int t = A[j + 1];
A[j + 1] = A[r];
A[r] = t;
return j + 1;
}
void Qsort(int *A,int p,int r){
if(r > p){
int P = partition(A,p,r);
Qsort(A,p,P - 1);
Qsort(A,P + 1,r);
}
}
int main(){
int n,i;
printf("enter size:");
scanf("%d",&n);
int A[n];
printf("enter array:");
for(i = 0;i < n;i++)
scanf("%d",&A[i]);
Qsort(A,0,n - 1);
printf("Sorted array:");
for(i = 0;i < n;i++)
printf("%d ",A[i]);
return 0;
}
