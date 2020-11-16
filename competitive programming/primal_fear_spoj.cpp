#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime(1000000, true);

void fillPrime(){

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i < 1000000; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j < 1000000; j += i)
				is_prime[j] = false;
		}
	}

}

bool haveZero(int n){

	while(n){
		if(n%10 == 0)
			return true;
		n /= 10;
	}

	return false;

}

vector<int> fillAns(){

	bool isAns;
	int p, t;
	vector<int> ans;

	for(int i = 2;i < 1000000;i++){
		if(haveZero(i) or !is_prime[i])
			continue;
		isAns = true;
		p = 1;
		do{
			t = i%(int)pow(10,p);
			if(!is_prime[t]){
				isAns = false;
				break;
			}
		}while(i/pow(10,p++));

		if(isAns)
			ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	unique(ans.begin(), ans.end());

	return ans;

}

int main() 
{
	fillPrime();
	
	vector<int> v;

	v = fillAns();

	//cout << ans.size();

	// for(int i = 0;i < 1000;i++){
	// 	cout << ans[i] << endl;
	// }

	int T, n, sz = v.size()-1;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &n);

		if(n == 1)
			printf("0\n");

		else{
			int st = 0, en = v.size()-1, mi;

			while(st < en){

				if(en == st+1)
					break;

				mi = st + (en - st)/2;

				if(v[mi] > n)
					en = mi;

				else
					st = mi;

			}

			if(v[en] <= n)
				printf("%d\n", en+1);
			else
				printf("%d\n", st+1);
		}
	}
}
