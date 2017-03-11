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
int* a=new int [5000001];
ll funct(int n)
{	
	if(n<=5000000){ll t=a[n];return t;}
	else {ll fun=funct(n/2)+funct(n/3)+funct(n/4);
		return fun;}
}


int main() 
{	
	a[0]=0;a[1]=1;a[2]=2;a[3]=3;a[4]=4;
	for(int i=5;i<=5000000;i++)
	{
		int t1=a[i/2]+a[i/3]+a[i/4];
		a[i]=max(i,t1);
	}
	//for(int i=0;i<30;i++)
	//	cout<<i<<" "<<a[i]<<" | ";
	while(true)
	{	string s;
		cin>>s;
		if(s.length()==0)break;
		int n;
		stringstream ss(s);
		ss>>n;
		
		cout<<funct(n)<<endl;
	}
	
}