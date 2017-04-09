#include <bits/stdc++.h>

using namespace std;

int a [1005];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int z = 1; z<=t; z++){
		string s; int k;
		cin >> s;
		cin >> k;
		int n = s.length();
		int n_flips = 0;
		int flag = 0;
		int count = 0;
		for (int i=0; i<n; i++){
			a[i] = 0;
		}
		for(int i = 0; i < n; i++){
			if((s[i] == '+' && n_flips == 0) || (s[i] == '-' && n_flips == 1)){
				;				
			}
			else if(i <= n-k){
				n_flips = (n_flips + 1) %2;
				a[i] = 1;
				count++;
			}
			else{
				cout<<"Case #"<<z<<": "<<"IMPOSSIBLE"<<endl;
				flag = 1;
				break;
			}
			int idx = i + 1 - k;
			if(idx >= 0 && a[idx] > 0){n_flips = (n_flips + 1) %2;}
		}
		if(flag == 0){
			cout<<"Case #"<<z<<": "<<count<<endl;
		}
	}

}