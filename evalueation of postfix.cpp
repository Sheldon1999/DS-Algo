#include<iostream>
using namespace std;
#define max_size 101
float A[max_size];
int top = -1;
void push(float a){
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
float chutiya(string a){
int len = -1,z = 0;
float p = 1,num = 0;
for(int i = 0;a[i] != '\0';i++){
len = len + 1;
if(a[i] == '.')
z = 1;
else if(z == 0)
num = num * 10 + (a[i] - '0');
else if(z == 1){
p = p * 10;
num = num + (a[i]  - '0')/p;
}
}
if(z == 1){
cout.precision(len);
}
return num;
}
void postfix(string *a,int n){
for(int i = 0;i < n;i++){
if((a[i] == "+")||(a[i] == "-")||(a[i] == "*")||(a[i] == "/")||(a[i] == "^")){
float op1 = A[top];
pop();
float op2 = A[top];
pop();
if(a[i] == "+")
push(op2 + op1);
else if(a[i] == "-")
push(op2 - op1);
else if(a[i] == "*")
push(op2 * op1);
else if(a[i] == "/")
push(op2 / op1);
else if(a[i] == "^"){
if((op1 - (int)op1) == 0){
int mul = 1;
for(int i = 1;i <= op1;i++)
mul = op2*mul;
push(mul);
}
else
cout << "☹ Please enter a vaild expression" << "\n";
exit(0);
}
}
else
push(chutiya(a[i]));
}
}
int main(){
int n;
cout << "Enter the size:";
cin >> n;
string a[n];
cout << "enter the element:";
for(int i = 0;i < n;i++)
cin >> a[i];
postfix(a,n);
cout << "Value of Expression:" << A[top];
return 0;
}
