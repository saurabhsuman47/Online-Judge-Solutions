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
	int a,b,c;
	sc(a);sc(b);sc(c);
	while(a!=0 || b!=0 || c!=0)
	{
		if(b*b==a*c){cout<<"GP"<<" "<<(c*c/b)<<endl;}
		else cout<<"AP"<<" "<<c+(c-b)<<endl;
		sc(a);sc(b);sc(c);
	}

}