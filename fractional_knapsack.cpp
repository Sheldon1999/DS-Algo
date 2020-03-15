#include<iostream>
#include<iomanip>
using namespace std;
int main()
 {
	    int N , W;
	    float n;
	    cout << "enter the number of items and total weights:";
	    cin >> N >> W;
	    float v[N],w[N];
	    cout << "enter (profit , weight):";
	    for(int i = 0;i < N;i++){
	        cin >> v[i] >> w[i];
	        if(i > 0){
	            float key = (v[i]/w[i])*1.00,kv = v[i],wv = w[i];
		        int j = i - 1;
		        while((j >= 0)&&(((v[j]/w[j])*1.00) > key)){
			        v[j + 1] = v[j];
			        w[j + 1] = w[j];
			        j--;
		        }
		        v[j + 1] = kv;
		        w[j + 1] = wv;
	        }
	    }	
	    float total = 0.00;
	    int i = N-1;
	    while(i >= 0){
	        if(W < w[i]){
	            total = total + (v[i]*(W/w[i]));
	            break;
	        }
	        else{
	            W = W - w[i];
	            total = total + v[i];
	        }
	        i--;
	    }
	    cout << "total profit :" << (total*1.00) << endl;
}
