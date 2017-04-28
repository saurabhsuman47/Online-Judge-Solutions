#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for(int z = 1; z <= t; z++){
	
		int b; ll n;
		cin>>b>>n;

		ll a[b];
		for(int i = 0; i < b; i++){
			cin>>a[i];
		}

		ll start = 0;
		ll end = 1000000000000000;
		int idx = -1;
		while(start <= end){
			ll mid = (start + end)/2;
			ll count = 0;
			ll per = 0;

			for(int i = 0; i < b; i++){
				count += (mid / a[i]);
				if(mid % a[i] > 0)count++;
				if(mid % a[i] == 0)per++;
			}

			if(per > 0 && count + per >=n && count < n){        
				ll temp = n - count;
				for(int i = 0; i < b; i++){
					if(mid % a[i] == 0)temp--;
					if(temp == 0){
						idx = i;
						break;
					}
				}
				break;
			}
			else if(count >= n){
				end = mid -1;
			}
			else{
				start = mid + 1;
			}
			
		}

		cout<<"Case #"<<z<<": "<<idx+1<<endl;
	}
}


