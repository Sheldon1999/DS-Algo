#include<iostream>
using namespace std;

bool isSafe(int x,int y,int sol[4][4]){
	if((x >= 0)&&(x < 4)&&(y >= 0)&&(y < 4)&&(sol[x][y] == 1))
		return true;
	else
		return false;
}

bool nextPath(int x,int y,int sol[4][4]){
	if((x == 3)&&(y == 3)){
		sol[x][y] = 2;
		return true;
	}

	if(isSafe(x,y,sol) == false)
		return false;

	else{
		sol[x][y] = 2;
		if(nextPath(x+1,y,sol) == true)
			return true;
		if(nextPath(x,y+1,sol) == true)
			return true;
		sol[x][y] = 1;
		return false;
	}
}

int main(){
	int sol[4][4];
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++)
			cin >> sol[i][j];
	}
	
	if(nextPath(0,0,sol) == false)
		cout << "can't possible!!!";
	else{
		cout << "path of rat is represented by 2 :\n";
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++)
				cout << sol[i][j] << " ";
			cout << "\n";
		}
	}
}

