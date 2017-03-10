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
#define sc(x) scanf("%lld",&(x))

int main() 
{	
	ll n;
	sc(n);
	ll grundy=n%10;
	if(grundy==0)cout<<"2"<<endl;
	else
	{
		cout<<"1"<<endl;
		cout<<grundy<<endl;
	}

}