#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for(int z = 1; z <= t; z++){
		int a[2505];
		for(int i = 0; i < 2505; i++){
			a[i] = 0;
		}
		int n;
		cin>>n;
		for(int i = 0; i < 2*n -1; i++){
			for(int j = 0; j < n; j++){
				int t1;
				cin>>t1;
				a[t1]++;
			}
		}
		int b[n];
		int idx = 0;
		for(int i = 0; i < 2505; i++){
			if(a[i] != 0){
				if(a[i] % 2 == 1){
					b[idx] = i;
					idx++;
				}
			}
		}

		sort(b, b+n);
		cout<<"Case #"<<z<<": ";
		for(int i = 0 ; i < n; i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
	


}

