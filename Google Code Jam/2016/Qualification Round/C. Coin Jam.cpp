#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	int N, J;
	cin >> N >> J;
	//cout << N << " " << J << endl;
	cout << "Case #1:" << endl;
	int countx = 0;
	for (int i = 0; i <= N - 10; i++){
		for (int j = 0; j <= N - 10 - i; j++){
			for (int k = 0; k <= N - 10 - i - j; k++){
				int l = N - 10 - i - j - k;
				if (l < 0)continue;
				//cout << i << " " << j << " " << k << " " << l << endl;
				cout << "11";
				for (int ii = 1; ii <= i; ii++)cout << "0";
				cout << "11";
				for (int jj = 1; jj <= j; jj++)cout << "0";
				cout << "11";
				for (int kk = 1; kk <= k; kk++)cout << "0";
				cout << "11";
				for (int ll = 1; ll <= l; ll++)cout << "0";
				cout << "11";

				cout << " ";

				cout << "3 2 5 2 7 2 3 2 11" << endl;
				countx++;
				if (countx >= J)break;
			}
			if (countx >= J)break;
		}
		if (countx >= J)break;
	}
	


}

