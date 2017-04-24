#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

#define sc(x) scanf("%d\n",&(x))

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int n;
		sc(n);
		if (n == 0)cout << "Case #" << z << ": " << "INSOMNIA" << endl;
		set<int> myset;
		for (int i = 1; i <= 100; i++){
			int t1 = i*n;
			while (t1 != 0){
				int t2 = t1 % 10;
				myset.insert(t2);
				t1 /= 10;
			}
			if (myset.size() == 10){
				cout << "Case #" << z << ": " << i*n << endl;
				break;
			}
		}
		if (myset.size() < 10){
			cout << n << endl;
			cout << "size " << myset.size() << endl;
		}
		
	}
}