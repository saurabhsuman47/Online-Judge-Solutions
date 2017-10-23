#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool CheckIfBalanced(string s){
    stack<char> stack1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack1.push(s[i]);
        }
        else{
            if(stack1.empty())return false;
            if(s[i] == ')' && stack1.top() != '(')return false;
            if(s[i] == '}' && stack1.top() != '{')return false;
            if(s[i] == ']' && stack1.top() != '[')return false;
            stack1.pop();
        }
    }
    if(!stack1.empty())return false;
    return true;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string op = CheckIfBalanced(s)?"balanced":"not balanced";
	    cout<<op<<endl;
	}
	return 0;
}
