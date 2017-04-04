#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod=1000000007ll;
double eps=1e-8;
const int N=100001;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

int a[26];

////************
int main()
{
	int t;
	sc(t);

	while(t--)
	{
		string s;
		cin>>s;
		fori(26)a[i]=0;
		int len=s.length();
		//cout<<"len "<<len<<endl;
		int flag=0;
		for(int i=len-1;i>=0;i--)
		{
			char c=s[i];
			
			int t1=c-'a';
			//cout<<"t1 "<<t1<<endl;
			int idx=-1;
			for(int j=t1+1;j<26;j++)
			{
				if(a[j]!=0){idx=j;break;}
			}
			a[t1]+=1;
			if(idx==-1){continue;}
			else
			{
				flag=1;
				s[i]='a'+idx;
				a[idx]-=1;
				int ii=i+1;
				forj(26)
				{
					for(int k=0;k<a[j];k++)
					{
						s[ii]='a'+j;
						ii++;
					}
				}
				cout<<s<<endl;

				break;
			}

		}
		if(flag==0)printf("%s\n","no answer");
	}
	

	


}