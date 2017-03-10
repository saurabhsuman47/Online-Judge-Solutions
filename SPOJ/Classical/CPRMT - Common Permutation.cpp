#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
#define sc(x) scanf("%s",&x)

int main()
{	string a,b;
	while(cin>>a>>b)
	{
		
		int la=a.length();
		int lb=b.length();
		char aa[26];
		char bb[26];
		for(int i=0;i<26;i++)
		{
			aa[i]=0;bb[i]=0;
		}
		for(int i=0;i<la;i++)
		{
			int t1=a[i];
			aa[t1-97]++;

		}
		for(int i=0;i<lb;i++)
		{
			int t1=b[i];
			bb[t1-97]++;
			
		}
		for(int i=0;i<26;i++)
		{
			int t1=min(aa[i],bb[i]);
			char cc=97+i;
			for(int j=0;j<t1;j++)
			{
				cout<<cc;

			}
		}
		cout<<endl;

	}
}