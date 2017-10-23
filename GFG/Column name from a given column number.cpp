#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    
	    char c[10];
	    int i = 0;
	    while(true){
	        n--;
	        c[i] =  'A' +  (n % 26);
	        n /= 26;
	        i++;
	        if(n == 0){
	            break;
	        }
	    }
	    for(int j = i - 1; j >= 0; j--){
	        cout<<c[j];
	    }
	    cout<<endl;
	}
	return 0;
}
