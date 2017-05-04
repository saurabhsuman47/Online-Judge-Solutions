#include<bits/stdc++.h>
using namespace std;
 
int EvaluateArithmeticExpression(int operand1, int operand2, char _operator){
	if(_operator == '+'){
		return operand1 + operand2;
	}
	else if(_operator == '-'){
		return operand1 - operand2;
	}
	else if(_operator == '*'){
		return operand1 * operand2;
	}
	
}
 
string InfixToPostfix(string s){
	string result = "";
	stack<char> s1;
	for(int i = 0; i<s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			result += s[i];
		}
		else if(s[i] == '('){
			s1.push(s[i]);
		}
		else if(s[i] == ')'){
			while(s1.top() != '('){
				result += s1.top();
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
				result += s1.top();
				s1.pop();
 
			}
			s1.push(s[i]);
		}
	}
	while(!s1.empty()){
	    result += s1.top();
	    s1.pop();
	}
	return result;
}
 
int EvaluatePostfix(string s){
	stack<int> s1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			s1.push(s[i] - '0');
		}
		else{
			int t1 = s1.top();
			s1.pop();
			int t2 = s1.top();
			s1.pop();
			int res = EvaluateArithmeticExpression(t2, t1, s[i]);
			s1.push(res);
		}
	}
	return s1.top();
}
 
 
int main(){
    //freopen("input.txt", "r", stdin);
	
    string s;
    cin>>s;
	string postfix = InfixToPostfix(s);
    cout<<EvaluatePostfix(postfix)<<endl;
 
}
