#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, s;
	    cin>>n>>s;
	    int a[n];
	    int temp1;
	    int tempsum = 0;
	    for(int i = 0; i < n; i++){
	        cin>>temp1;
	        tempsum += temp1;
	        a[i] = tempsum;
	    }
	    int i = 0, j = 0;
	    int ii = -1, jj = -1;
	    while(i < n && j < n){
	        if(i==0){
	            temp1 = a[j];
	        }
	        else temp1 = a[j] - a[i - 1];
	        if(temp1 == s){
	            ii = i;
	            jj = j;
	            j++;
	            break;
	        }
	        else if(temp1 < s){
	            j++;
	        }
	        else{
	            i++;
	        }
	    }
	    if(ii == -1){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<ii + 1<<" "<<jj + 1<<endl;
	    }
	    
	}
	return 0;
}
