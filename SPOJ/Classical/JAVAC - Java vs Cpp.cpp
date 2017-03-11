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
	while(1)
	{
		string s;
		cin>>s;
		
		int ki=0;
		int kc=0;
		int l=s.length();
		if(l==0)break;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='_'){ki=1;}
			if(s[i]>=65 && s[i]<=90){kc=1;}
		}
		if(kc==0 && ki==0)cout<<s<<endl;
		if(kc==1 && ki==1)cout<<"Error!"<<endl;
		if(kc==1 && ki==0)
		{
			//java
			if(s[0]>=65 && s[0]<=90){cout<<"Error!";}
			else
			{
				for(int i=0;i<l;i++)
				{
					if(s[i]>=65 && s[i]<=90){char cc=s[i]+32;cout<<"_"<<cc;}
					else cout<<s[i];
				}
			}
			cout<<endl;
		}
		
		if(kc==0 && ki==1)
		{
			//cpp
			if(s[0]=='_' || s[l-1]=='_'){cout<<"Error!";}
			else{int f=0;
				for(int i=0;i<l-1;i++)
				if(s[i]=='_' && s[i+1]=='_'){cout<<"Error!";f=1;}
				
			
				if(f==0)
				{
					for(int i=0;i<l;i++)
					{
						if(s[i]=='_'){s[i+1]-=32;continue;}
						cout<<s[i];
					}
				}
			}
			cout<<endl;
		}
		
	}

	
}