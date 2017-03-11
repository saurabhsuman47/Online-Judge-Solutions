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
#define scl(x) scanf("%f",&(x))


int main() 
{	
	int tt;
	scanf("%d",&tt);
	for(int pp=0;pp<tt;pp++)
	{
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		//scanf("%f",&d);
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		//double k=0.0;
		
		double t=(a+b+c+d)/2;
		double tt=(t-a)*(t-b)*(t-c)*(t-d);
		tt=sqrt(tt);
		//cout<<"t "<<t<<endl;
		
		printf("%.2f \n",tt);


	}
	
}