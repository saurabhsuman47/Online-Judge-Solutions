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
	while(1)
	{
		string s;
		cin>>s;
		if(s.length()==0)break;
		else if(s.length()==1 && s[0]=='1')cout<<"1"<<endl;
		else
		{
			int len=s.length();
			char a[len+1];
			int carry=0;
			int i=len-1;
			for(;i>=0;i--)
			{
				int t1=(s[i]-48)*2+carry;
				a[i+1]=t1%10+48;
				carry=t1/10;
			}
			a[0]=carry+48;
			//cout<<a[0]<<a[1]<<endl;
			//int t2=s[len-1]-48;
			//cout<<"t2 "<<t2<<endl;
			
				i=len;carry=0;
				
				//cout<<"len "<<len<<endl;
				for(;i>=0;i--)
				{
					
					int t1=(a[i]-48);
					if(i==len)
					{	if(t1-carry>=2){a[i]=(t1-2)+48;break;}
						
						else
						{
							t1+=10;t1-=2;carry=1;a[i]=t1+48;
						}
					}
					if(i!=len)
					{
						if(t1-carry>=0){a[i]=(t1-carry)+48;break;}
						else
						{
							t1+=10;t1-=carry;carry=1;a[i]=t1+48;
						}
					}
									
				}
			

			
			if(a[0]!='0'){cout<<a[0];}
			for(int j=1;j<=len;j++)
				{cout<<a[j];}
			cout<<endl;




		
		}
	}
	
}