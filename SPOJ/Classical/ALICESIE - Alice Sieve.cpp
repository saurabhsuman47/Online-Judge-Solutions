#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)





////************
int main()
{
	int t;
	sc(t);
	while(t--)
	{
		int n;
		sc(n);
		if(n%2==0)printf("%d\n", n/2);
		else printf("%d\n", n/2+1);
	}
	
	


}