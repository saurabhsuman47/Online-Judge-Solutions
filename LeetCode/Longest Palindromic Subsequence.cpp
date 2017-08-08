class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        int dp[len][len];
        for(int i  = 0; i < len; i++){
            dp[i][i] = 1;
        }
        int sol = 1;
        for(int k = 1; k < len; k++){
            for(int i = 0; i < len; i++){
                int j = i + k;
                if(j >= len) break;
                int temp = 0;
                if(s[i] == s[j]){
                    temp = 2;
                }
                if(i + 1 <= j -1){
                        dp[i][j] = dp[i + 1][j - 1] + temp;
                }
                else{
                    dp[i][j] = temp;
                }
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(dp[i][j] > sol){
                    sol = dp[i][j];
                }
            }
        
        }        
        return sol;
    
    }
};
