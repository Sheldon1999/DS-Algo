#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "enter no of jobs:";
	cin >> n;
	cout << "enter (profit , deadline , JobID):";
	int p[n],d[n],max = 0;
	char ID[n];
	for(int i = 0;i < n;i++){
		cin >> p[i] >> d[i] >> ID[i];
		if(d[i] > max)
			max = d[i];
		if(i > 0){
			int key = p[i];
			int key_d = d[i];
			char key_ID = ID[i];
			int j = i - 1;
			while((j >= 0)&&(p[j] > key)){
				p[j + 1] = p[j];
				d[j + 1] = d[j];
				ID[j + 1] = ID[j];
				j--;
			}
			p[j + 1] = key;
			d[j + 1] = key_d;
			ID[j + 1] = key_ID;
		}
	}
	int total = 0,slot = 0,i = n-1;
	cout << "order of jobs:";
	while(i >= 0){
		if(slot > max)
			break;
		else{
			if(d[i] > slot){
				slot++;
				if(slot <= max){
					total += p[i];
					cout << ID[i] << " ";
				}
			}
		}
		i--;
	}
	cout << "\ntotal profit:" << total;
	return 0;
}

