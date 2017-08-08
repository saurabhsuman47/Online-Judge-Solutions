class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int dp[len][len];
        for(int i  = 0; i < len; i++){
            dp[i][i] = 1;
        }
        int sol = 1;
        int idxi = 0, idxj = 0;
        for(int k = 1; k < len; k++){
            for(int i = 0; i < len; i++){
                int j = i + k;
                if(j >= len) break;
                if(s[i] != s[j]){
                    dp[i][j] = 0;
                    continue;
                }
                if(i + 1 <= j -1){
                    if(dp[i + 1][j - 1] == 1){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    dp[i][j] = 1;
                }
                if(dp[i][j] == 1 && j - i + 1 > sol){
                    sol = j - i + 1;
                    idxi = i;
                    idxj = j;
                }
            }
        
        }
        
        string res = "";
        for(int i = idxi ; i <= idxj; i++){
            res += s[i];
        }
        return res;
    }
};
