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
const ll mod=1000000007ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{
		int e,f;
		sc(e);sc(f);
		int t1=f-e;
		int n;sc(n);
		int a[n];
		int b[n];
		
		for(int i=0;i<n;i++)
		{
			int p,w;
			sc(a[i]);sc(b[i]);//b is weight
			
		}
		int sol[t1+1];
		for(int i=0;i<=t1;i++)
		{
			sol[i]=1000000000;
		}
		sol[0]=0;
		for(int i=1;i<=t1;i++)
		{	
			for(int j=0;j<n;j++)
			{
				if(i-b[j]>=0)
				{
					sol[i]=min(sol[i-b[j]]+a[j],sol[i]);
				}
			}
		}
		if(sol[t1]==1000000000)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<sol[t1]<<"."<<endl;


	}

}