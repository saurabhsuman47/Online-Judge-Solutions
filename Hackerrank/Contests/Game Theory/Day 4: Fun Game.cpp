#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int a[2][1001];
int f[1001];
int sol[2];

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		sol[0] = 0;
		sol[1] = 0;
		for (int i = 0; i<n; i++){
			cin >> a[0][i];
			f[i] = 0;
		}
		for (int i = 0; i<n; i++){
			cin >> a[1][i];
			f[i] = 0;
		}

		int p = 0;
		for (int i = 0; i<n; i++){
			int diff = 0;
			int idx = 0;
			for (int j = 0; j<n; j++){
				if (f[j] == 1)continue;
				int t1 = a[p][j];
				int t2 = a[(p + 1) % 2][j];
				if (t1>t2){
					int t3 = (t1 - t2);
					if (t3>=diff){
						diff = t1;
						idx = j;
					}
				}
				else{
					int t3 = abs(t1 - t2);
					if (t3>=diff){
						diff = t3;
						idx = j;
					}
				}

			}
			sol[p] += a[p][idx];
			p = (p + 1) % 2;
			
			f[idx] = 1;
			//cout << idx << endl;
		}
		//cout << sol[0] << " " << sol[1] << endl;
		if (sol[0]>sol[1])cout << "First" << endl;
		else if (sol[0]<sol[1])cout << "Second" << endl;
		else cout << "Tie" << endl;



	}
}

