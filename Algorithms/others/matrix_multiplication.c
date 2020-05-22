#include<stdio.h>
#include<stdlib.h>
int main(){
int m1,n1,m2,n2,i,j;
printf("enter the order of first matrix:");
scanf("%d %d",&m1,&n1);
printf("enter the order of second matrix:");
scanf("%d %d",&m2,&n2);
if(n1 != m2){
printf("impossible.....");
exit(0);
}
else{
int A[m1][n1];
printf("enter matrix:\n");
for(i = 0;i < m1;i++){
for(j = 0;j < n1;j++)
scanf("%d",&A[i][j]);
}
i = 0;
j = 0;
int B[m2][n2];
printf("enter matrix:\n");
for(i = 0;i < m2;i++){
for(j = 0;j < n2;j++)
scanf("%d",&B[i][j]);
}
i = 0;
j = 0;
int M[m1][n2],sum,k;
for(i = 0;i < m1;i++){
for(j = 0;j < n2;j++){
for(k = 0;k < n1;k++){
if(k == 0)
sum = A[i][0] * B[0][j];
else{
sum = sum + A[i][k] * B[k][j];
}
}
M[i][j] = sum;
}
}
printf("hence multiplied matrix:\n");
for(i = 0;i < m1;i++){
for(j = 0;j < n2;j++)
printf("%d ",M[i][j]);
printf("\n");
}
}
return 0;
}
