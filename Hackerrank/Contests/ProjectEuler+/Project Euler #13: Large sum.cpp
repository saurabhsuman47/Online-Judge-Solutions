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
	int n;
	sc(n);
	string s[n];
	fori(n)cin>>s[i];
	//cout<<s[0]<<endl;
	int carry=0;
	int idx=0;
	int a[60];
	fori(50)
	{
		int sum=carry;
		forj(n)
		{
			int t1=s[j][49-i]-48;
			sum+=t1;
		}
		int t1=sum%10;
		a[idx]=t1;idx++;
		sum/=10;
		carry=sum;

	}
	//cout<<endl;
	while(carry!=0)
	{
		a[idx]=carry%10;
		carry/=10;
		idx++;
	}
	idx--;
	while(idx>=0){if(a[idx]==0)idx--;else break;}
	//cout<<idx<<endl;
	if(idx<9)
	{
		int ii=idx;
		
		while(ii<9)
		{
			cout<<"0";
			
			ii++;
		}
		while(idx>=0)
		{
			cout<<a[idx];
			idx--;
		}

	}
	else
	{
		int count=0;
		while(count<10)
		{
			cout<<a[idx];
			count++;
			idx--;
		}
	}


}
