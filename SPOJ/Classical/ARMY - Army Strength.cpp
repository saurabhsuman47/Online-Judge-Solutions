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
	int t;
	scanf("%d",&t);
	for(int pp=0;pp<t;pp++)
	{	//cout<<pp+1<<endl;
		int ng,nm;
		sc(ng);sc(nm);
		int a[ng];int b[nm];
		for(int i=0;i<ng;i++)
		{
			sc(a[i]);
		}	
		for(int i=0;i<nm;i++)
		{
			sc(b[i]);
		}
		sort(a,a+ng);
		sort(b,b+nm);
		int ii=0;int jj=0;
		while(true)
		{
			if(a[ii]<b[jj]){ii+=1;if(ii==ng){cout<<"MechaGodzilla"<<endl;break;}}
			else if(a[ii]>=b[jj]){jj+=1;if(jj==nm){cout<<"Godzilla"<<endl;break;}}
		}	

	}
	
}