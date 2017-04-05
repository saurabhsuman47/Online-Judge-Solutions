#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
double eps=1e-8;
typedef long long ll;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))

int main() 
{	
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	
{	int n;int m;
	cin>>n;cin>>m;
	//ll a[n][n][n];
	int bx[m];
	int by[m];
	int bz[m];
	ll bw[m];
	int index=0;

	for(int p=0;p<m;p++)
	{
		string s1;
		cin>>s1;
		int len=s1.length();
		if(len==6)
		{
			int x,y,z;ll w;
			cin>>x;cin>>y;cin>>z;cin>>w;
			if(index==0)
			{bx[index]=x;by[index]=y;bz[index]=z;bw[index]=w;index++;}
			else
			{	int flag=0;
				for(int i=0;i<index;i++)
					if(bx[i]==x && by[i]==y && bz[i]==z){bw[i]=w;flag=1;break;}
				if(flag==0){bx[index]=x;by[index]=y;bz[index]=z;bw[index]=w;index++;}
			}

		}

		if(len==5)
		{	int x1,x2,y1,y2,z1,z2;
					cin>>x1;cin>>y1;cin>>z1;cin>>x2;cin>>y2;cin>>z2;
			if(index<=0)cout<<"0"<<endl;
			else
				{
					ll ans=0;
					
					for(int i=0;i<=index-1;i++)
					{
						if((bx[i]>=x1 && bx[i]<=x2) && (by[i]>=y1 && by[i]<=y2) && (bz[i]>=z1 && bz[i]<=z2)){ans+=bw[i];}
					}
					cout<<ans<<endl;
				}

		}

	}

}

}
