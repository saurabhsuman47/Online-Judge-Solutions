#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



const ll mod=1000000007ll;
double eps=1e-8;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)



////************
int main()
{
	int tt;
    sc(tt);
	while(tt--)
	{
		int n,k;
		sc(n);sc(k);
		int t1=n/2;
		if(k<t1)cout<<k*2+1<<endl;
		else cout<<(n-k-1)*2<<endl;
	}
}
