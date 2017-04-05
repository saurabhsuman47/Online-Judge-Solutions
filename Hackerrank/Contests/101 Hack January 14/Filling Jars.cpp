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
#define sc(x) scanf("%f",&(x))

int main() 
{	
	double n;
	int m;
	cin>>n;cin>>m;
	double count=0;
	for(int p=0;p<m;p++)
	{
		double a,b,k;
		cin>>a;cin>>b;cin>>k;
		count+=(b-a+1)*k;
	}
	double t=count/n;
	//t+=0.5;
	ll t1=(ll)t;
	cout<<t1<<endl;


}
