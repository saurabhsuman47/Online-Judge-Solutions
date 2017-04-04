#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];

int main() {
	 
	a[1]=0;
	for(int i=2;i<=1000000;i++){  
		if(a[i]==0){ a[i] = 1;}      
		for(int j=2;j*i<=1000000;j++){                
			a[i*j]=max(a[i*j],a[i]+1); 
		}
	}

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sol=0;
		int t1;
		while(n--){
			cin>>t1;
			sol^=a[t1];
		}
		if(sol==0)cout<<"2"<<endl;
		else{
			cout<<"1"<<endl;
		}
	}
		
		
}

