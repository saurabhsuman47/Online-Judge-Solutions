#include <iostream>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    int a[n];
	    int sum[n];
	    int temp = 0;
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	        temp += a[i];
	        sum[i] = temp;
	    }
	    int sol = 0;
	    int flag = 0;
	    for(int i = 1; i <= n; i++){
	        for(int j = 0; j <= n - i; j++){
	            int temp = (j - 1 >= 0)?sum[j - 1] : 0;
	            if(sum[j + i - 1] - temp > x){
	                sol = i;
	                //cout<<"j "<<j<<endl;
	                flag = 1;
	                break;
	            }
	        }
	        if(flag == 1)break;
	    }
	    cout<<sol<<endl;
	}
	return 0;
}
