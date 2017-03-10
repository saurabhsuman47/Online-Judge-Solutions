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
	{
		int a,b;
		sc(a);sc(b);
		int m[a][b+2];
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<=b+1;j++)
			{
				m[i][j]=0;
			}
		}
		for(int i=0;i<a;i++)
		{
			for(int j=1;j<b+1;j++)
			{
				sc(m[i][j]);
			}
		}
		for(int i=1;i<a;i++)
		{
			for(int j=1;j<b+1;j++)
			{
				int t1=max(m[i-1][j-1],m[i-1][j+1]);
				m[i][j]=m[i][j]+max(t1,m[i-1][j]);

			}
		}
		int max=0;
		for(int j=1;j<=b;j++)
		{
			if(m[a-1][j]>max)max=m[a-1][j];
		}
		cout<<max<<endl;

	}
	
}