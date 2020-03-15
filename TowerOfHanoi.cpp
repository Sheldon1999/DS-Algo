#include<iostream>
using namespace std;
void T_O_H(int n,char sor,char des,char aux){
if(n == 1){
cout << "moving 1 disk from " << sor << " to " << des << "\n";
return;
}
if(n - 2 > 0){
cout << "moving " << n-1 << " disks from " << sor << " to " << aux << "\n";
}
T_O_H(n-1,sor,aux,des);
if(n - 2 > 0)
cout << "moving " << n-2 << " disks from " << sor << " to " << des << "\n";
else
cout << "moving " << n-1 << " disks from " << sor << " to " << des << "\n";
T_O_H(n-1,aux,des,sor);
}
int main(){
int n;
cout << "Enter the numbers of disks:";
cin >> n;
char S,D,A;
T_O_H(n,'S','D','A');
cout << "All disks have transferred from source to destination.";
return 0;
}

