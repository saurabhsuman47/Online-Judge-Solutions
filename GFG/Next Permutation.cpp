#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int count[100];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    for(int i = 0; i < 100; i++){
	        count[i] = 0;
	    }
	    int temp = -1;
	    int flag = 0;
	    for(int i = n - 1; i >= 0; i--){
	        if(a[i] < temp){
	            //cout<<a[i]<<" "<<temp<<endl;
	            flag = 1;
	            count[a[i]]++;
	            for(int j = 0; j < 100; j++){
	                if(j > a[i] && count[j] > 0){
	                    //cout<<"j "<<j<<endl;
	                    a[i] = j;
	                    count[j]--;
	                    int jj = 0;
	                    for(int k = i + 1; k < n; k++){
	                        while(count[jj]==0){
	                            jj++;
	                        }
	                        a[k] = jj;
	                        count[jj]--;
	                    }
	                    break;
	                }
	            }
	            break;
	        }
	        else{
	            temp = a[i];
	            count[a[i]]++;
	        }
	    }
	    if(flag == 1){
	        for(int i = 0; i < n; i++){
	            cout<<a[i]<<" ";
	        }
	        cout<<endl;
	    }
	    else{
	        for(int i = n - 1; i >= 0; i--){
	            cout<<a[i]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
