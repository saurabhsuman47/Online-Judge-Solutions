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
	ll min1=1000001;ll min2=1000001;
	for(int pp=0;pp<t;pp++)
	{
		int t1,t2;
		sc(t1);sc(t2);
		if(t1<min1)min1=t1;
		if(t2<min2)min2=t2;


	}
	cout<<min1*min2<<endl;
	
}
