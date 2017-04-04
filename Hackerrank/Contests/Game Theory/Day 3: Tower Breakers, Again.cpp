#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int g[100001];
int mex[1001];

void seive(){
	a[1]=0;
	for(int i=2;i*i<=100000;i++){  
		if(a[i]==0){      
			for(int j=2;j*i<=100000;j++){                
				a[i*j]=1;
			} 
		}
	}
}

void grundy(){
	for(int i=2;i<=100000;i++){
		if(a[i]==1){
			for(int j=0;j<=15;j++){
				mex[j]=0;
			}
			mex[0]=1;
			for(int j=2;j*j<=i;j++){
				if(i%j==0){
					int t1=j;
					int t2=i/j;
					if(t1%2){
						mex[g[t2]]=1;
					}
					if(t2%2){
						mex[g[t1]]=1;
					}
				}
			}
			for(int j=0;j<=15;j++){
				if(mex[j]==0){
					g[i]=j;
					break;
				}
			}

		}
		else{
			g[i]=1;
		}
	}
}
int main() {
	 
	//freopen("input.txt","r",stdin);
	seive();
	grundy();

	

	//for(int i=1;i<10;i++)cout<<g[i]<<" ";

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sol=0;
		int t1;
		while(n--){
			cin>>t1;
			sol^=g[t1];
		}
		if(sol==0)cout<<"2"<<endl;
		else{
			cout<<"1"<<endl;
		}
	}
		
		
}

