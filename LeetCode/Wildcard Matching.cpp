/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:    
	vector<vector<int>> dp;
    string s, p;
    bool isMatch(string _s, string _p) {
        s = _s; p = _p;
		for(int i = 0; i <= s.length(); i++){
			vector<int> vect_temp;
			for(int j = 0; j < p.length(); j++){
				vect_temp.push_back(-1);
			}
			dp.push_back(vect_temp);
		}
		return isMatchHelper(0, 0);
    }
    
    bool isMatchHelper(int sidx, int pidx){
        if(sidx < s.length() && pidx == p.length()){
            return false;
        }
        if(sidx == s.length()){
            if(pidx == p.length())return true;
            if(p[pidx] != '*') return false;           
        }
		if(dp[sidx][pidx] != -1) return dp[sidx][pidx];
        bool sol = false;        
        if(p[pidx] == '?'){
			sol = isMatchHelper(sidx + 1, pidx + 1);
        }
		else if(p[pidx] == '*'){
			sol = isMatchHelper(sidx, pidx + 1);
			int tsidx = sidx;
            while(tsidx < s.length()){
                sol |= (isMatchHelper(++tsidx, pidx + 1));
            } 
		}
		else{            
            if(s[sidx] == p[pidx]){
                sol = isMatchHelper(sidx + 1, pidx + 1);
            }
            else sol = false;                                 
        }
		dp[sidx][pidx] = sol;
		return dp[sidx][pidx];
    }
};
