#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define repi(l,r) for(int i=l;i<=r;i++)

#define forii(n) for(int ii=0;ii<n;ii++)
#define forjj(n) for(int jj=0;jj<n;jj++)
#define forkk(n) for(int kk=0;kk<n;kk++)


const int N=5005;

int a[N];
int b[N];
int cnt[N];

// set<int> mysa,mysb;
// set<int>:: iterator it1,it2;

stack<int> mys;


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		int n;sc(n);
		fori(n){
			sc(a[i]);
		}
		int flag=0;
		int cnt=0;
		while(flag==0){
			flag=1;
			int sol=0;
			int idx=0;
			fori(n){
				if(a[i]>0){
					a[i]--;
					idx=i;
					sol=i+1;
					flag=0;
					break;
				}
								
			}
			 if(flag==1)break;
			repi(idx+1,n-1){
				if(a[i]>0){
					a[i]--;
					sol*=27;
					sol+=(i+1);
					idx=i;
					break;
				}
			}
			mys.push(sol);
			repi(idx+1,n-1){
				if(a[i]>0){
					a[i]--;
					sol=i+1;
					mys.push(sol);
				}
			}
		}

		cout<<"Case #"<<z<<": ";
		while(!mys.empty()){
			int t1=mys.top();
			if(t1>26){
				char c1=(t1%27)-1 + 'A';
				t1/=27;
				char c2=(t1%27)-1 + 'A';
				cout<<c1<<c2<<" "; 
			}
			else{
				char c1=(t1%27)-1 + 'A';
				cout<<c1<<" ";
			}
			mys.pop();
		}
		cout<<endl;
	}


 		
	

}