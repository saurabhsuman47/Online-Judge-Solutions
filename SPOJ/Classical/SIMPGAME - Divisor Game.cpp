#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define sc(x) scanf("%d",&(x))
#define fori(x) for(int i=0; i<x; i++)
#define forj(x) for(int j=0; j<x; j++)
#define pb push_back
const int N=100005;

int a[N];
int count;
int b[N];

vector<int> v;
vector<int> v2;


void seive(){
	//a[1]=1;
	count=0;
	for(int i=2;i*i<N;i++){
		if(a[i]==0){
			for(int j=2;i*j<N;j++){
				a[i*j]=1;               
			}
		}
	}
}

void grundy(){
	a[1]=0;
	a[2]=0;
	a[3]=0;


	for(int i=4;i<N;i++){
		if(a[i]==0)continue;
		v.clear();
		v2.clear();
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				v.pb(j);
				v.pb(i/j);
			}
		}
		int n=v.size();		
		for(int j=0;j<n;j++){
			for(int k=j;k<n;k++){
				int t1=a[v[j]]^a[v[k]];
				v2.pb(t1);
				b[t1]=1;
			}
		}

		for(int j=0;j<N;j++){
			if(b[j]==0){
				a[i]=j;
				break;
			}
		}
		for(int j=v2.size()-1;j>=0;j--){
			b[j]=0;
		}
		


	}
}


int main(){
	seive();
	grundy();

	// for(int i=1;i<30;i++){
	//   cout<<a[i]<<" ";
	// }
	// cout<<endl;
	//freopen("input.txt","r",stdin);
	int t;
	sc(t);
	while(t--){
	 int n;
	 sc(n);
	 int val=0;
	 fori(n){
	     int t1;
	     sc(t1);
	     val=val^a[t1];
	 }
	 if(val==0)printf("%s\n","Bob");
	 else printf("%s\n","Alice");
	}



}





