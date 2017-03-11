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
typedef vector<int> vi;
typedef std::vector<long long> vl;
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	int b,p;
	sc(b);sc(p);
	//cout<<b<<" "<<p<<endl;
	while(b!=0 && p!=0)
	{
		int a[p+1][b+1];
		for(int i=0;i<=b;i++)
		{	for(int k=0;k<=p;k++)
			{
				a[k][i]=0;
			}
		}
		//cout<<"aa"<<endl;
		int fun[p+1];
		int cost[p+1];
		int funt[b+1];
		for(int i=0;i<=b;i++)
		{
			funt[i]=0;
		}
		for(int i=1;i<=p;i++)
		{
			sc(cost[i]);sc(fun[i]);
		}
		int solbuj=0,ii=0;
		for(int i=1;i<=b;i++)
		{	int jj=0;int kk=0;
			for(int j=0;j<i;j++)
			{
				
				for(int k=1;k<=p;k++)
				{
					if(i==j+cost[k] && a[k][j]==0)
					{
						if(funt[i]<funt[j]+fun[k]){funt[i]=funt[j]+fun[k];kk=k;jj=j;if(funt[i]>solbuj){solbuj=funt[i];ii=i;}}
					}
				}

			}
			for(int k=1;k<=p;k++)
			{
				if(a[k][jj]==1){a[k][i]=1;}

			}
			a[kk][i]=1;
		}
		cout<<ii<<" "<<solbuj<<endl;
		sc(b);sc(p);
		//if(b==0)break;
	}
	
}