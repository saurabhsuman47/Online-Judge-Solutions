#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for(int z = 1; z <= t; z++){
		string s;
		cin>>s;
		int len = s.length();
		char a[2*len];
		int l = len - 1, r = len;
		char temp = 20;
		for(int i  = 0; i < len; i++){
			if(s[i] >= temp){
				a[l] = s[i];
				l--;
				temp = s[i];
			}
			else{
				a[r] = s[i];
				r++;
			}

		}
		cout<<"Case #"<<z<<": ";
		for(int i = l + 1; i < r; i++){
			cout<<a[i];
		}
		cout<<endl;
	}
	


}

