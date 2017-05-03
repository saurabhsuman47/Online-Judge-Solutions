#include<bits/stdc++.h>
using namespace std;

map<char, int> precdence;
char operators[5] = {'+','-','*','/', '^'};


int main(){
    freopen("input.txt", "r", stdin);
    for(int i = 0;i<5;i++){
        precdence[operators[i]] = i;
    }
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> s1;
        for(int i = 0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                cout<<s[i];
            }
            else if(s[i] == '('){
                s1.push(s[i]);
            }
            else if(s[i] == ')'){
                while(s1.top() != '('){
                    cout<<s1.top();
                    s1.pop();
                }
                s1.pop();
            }
            else{
                while(true){
                    if(s1.empty())break;
                    if(s1.top() == '('){
                        break;
                    }  
                    if(precdence[s1.top()] >= precdence[s[i]]){
                        cout<<s1.top();
                        s1.pop();
                    } 
                    else break;

                }
                s1.push(s[i]);
            }
        }
        cout<<endl;
    }


}

