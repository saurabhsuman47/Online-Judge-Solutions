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
	int count12=0;
		int count14=0;
		int count34=0;
		int count=0;
	for(int pp=0;pp<t;pp++)
	{
		string s;
		cin>>s;
		if(s[0]=='1' && s[2]=='4')count14++;
		if(s[0]=='1' && s[2]=='2')count12++;
		if(s[0]=='3' && s[2]=='4')count34++;

	}
	if(count14>=count34){count+=count34;count14-=count34;}
	else{
		count+=count34;count14=0;
	}
	//cout<<count14<<endl;
	count+=count12/2;
	count12=count12%2;
	if(count12!=0){count+=count12;count14-=2;if(count14<0)count14=0;}
	count+=count14/4;
	if(count14%4!=0)count++;
	count++;
	cout<<count<<endl;
	
}