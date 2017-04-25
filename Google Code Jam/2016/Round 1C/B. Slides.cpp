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


const int N=55;

ll a[N];
ll c[N];
int d[N][N];
// set<int> mysa,mysb;
// set<int>:: iterator it1,it2;

// stack<int> mys;


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		
		ll b,m;
		scl(b);
		scl(m);
		fori(b+1){
			forj(b+1){
				d[i][j]=0;
			}
		}
		a[1]=0;
		a[2]=1;
		for(int i=3;i<=50;i++){
			a[i]=a[i-1]*2;
		}
		if(m>a[b]){
			cout<<"Case #"<<z<<": IMPOSSIBLE";		
			cout<<endl;
		}
		else if(m==a[b]){
			cout<<"Case #"<<z<<": POSSIBLE"<<endl;;
			for(int i=1;i<=b;i++){
				for(int j=i+1;j<=b;j++){
					d[i][j]=1;
				}				
			}	
			for(int i=1;i<=b;i++){
				for(int j=1;j<=b;j++){
					cout<<d[i][j]<<" ";
				}
				cout<<endl;
			}	
			
		}
		else{
			ll mm=m;
			int idx=0;
			while(mm!=0){
				c[idx]=mm%2;
				mm/=2;
				idx++;
			}
			// fori(idx){
			// 	cout<<c[i]<<" ";
			// }
			//cout<<endl;
			fori(idx){
				if(c[i]>0){
					int t1=b-i-1;
					d[1][t1]=1;
					for(int j=t1;j<=b;j++){
						for(int k=j+1;k<=b;k++){
							d[j][k]=1;
						}
					}
				}
			}

			cout<<"Case #"<<z<<": POSSIBLE"<<endl;

			for(int i=1;i<=b;i++){
				for(int j=1;j<=b;j++){
					cout<<d[i][j];
				}
				cout<<endl;
			}




		}
		
	}	
	

}