#include<iostream>
#define max_size 101
using namespace std;
int A[max_size];
int top = -1;
void push(int a){
if(top == max_size-1)
cout << "error:stack overflow";
else
top++;
A[top] = a;
}
void pop(){
if(top == -1)
cout << "error:stack underflow";
else
top--;
}
void check(char *a,int n){
for(int i = 0;i < n;i++){
if((a[i] == '(') || (a[i] == '{') || (a[i] == '['))
push(a[i]);
else if(a[i] == ')'){
push(a[i]);
if(a[top - 1] == '('){
pop();
pop();
}
}
else if(a[i] == '}'){
push(a[i]);
if(a[top - 1] == '{'){
pop();
pop();
}
}
else if(a[i] == ']'){
push(a[i]);
if(a[top - 1] == '['){
pop();
pop();
}
}
}
}
int main()
{
int n;
cout << "enter size:";
cin >> n;
char a[n];
for(int i = 0;i < n;i++){
cout << "Enter element-" << i + 1 << ":";
cin >> a[i];
}
check(a,n);
if(top == -1)
cout << "balanced";
else
cout << "Unbalanced";
return 0;
}







