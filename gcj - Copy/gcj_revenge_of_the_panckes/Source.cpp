#include<iostream>
#include<stdio.h>
#include<cstring>
#include<sstream>
using namespace std;

#define sc(x) scanf("%d",&(x))

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		string s;
		cin >> s;
		int n = s.length();
		int flips_count = 0;
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == '+')continue;
			else{
				flips_count++;
				
				if (s[0] == '-'){
					string temp_string = "";
					for (int j = 0; j <= i; j++){
						if (s[j] == '-')temp_string += '+';
						else{
							temp_string += '-';
						}
					}
					for (int j = i; j >= 0; j--){
						s[j] = temp_string[i - j];
					}

				}
				else{
					string temp_string = "";
					flips_count++;
					for (int j = 0; j <= i; j++){
						if (s[j] == '-')break;
						s[j] = '-';
					}
					for (int j = 0; j <= i; j++){
						if (s[j] == '-')temp_string += '+';
						else{
							temp_string += '-';
						}
					}
					for (int j = i; j >= 0; j--){
						s[j] = temp_string[i - j];
					}
				}
				
			}
			//cout << s << endl;
		}
		cout << "Case #" << z << ": " << flips_count << endl;

		
	}

}