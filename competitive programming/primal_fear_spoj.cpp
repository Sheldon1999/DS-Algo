// Changu and Mangu are afraid of prime numbers, but they are not afraid of all prime numbers. They were afraid of only a special kind of prime numbers. They are afraid of the prime numbers (without the digit zero, they love all the primes which have digits 0 in them) that remain prime no matter how many of the leading digits are omitted. For example, they are afraid of 4632647 because it doesn't have the digit 0 and each of its truncations (632647, 32647, 2647, 647, 47, and 7) are primes.

// You are given a simple task, given a number of N, find out the number of primes not greater that N, that changu and mangu are afraid of.

// Input
// The first line contains T, the number of test cases. T lines follow, each containing a number N.

// Output
// On each line print the number of primes not greater that N, that changu and mangu are afraid of.

// Example
// Input:
// 3
// 2
// 3
// 4

// Output:
// 1
// 2
// 2
// Constraints

// T ≤ 10^5

// 1 ≤ N < 10^6

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
