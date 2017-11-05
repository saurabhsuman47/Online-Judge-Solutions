int Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.length();
    int m = B.size();
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = 0;
        for(int j = 0; j < m; j++){
            if(B[j].length() > i + 1)continue;
            int mm = B[j].length();
            string str = A.substr(i + 1 - mm, mm);
            if(str == B[j]){
                if(i + 1 - mm == 0){
                    dp[i] = 1;
                    break;
                }
                else if(dp[i  - mm] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    if(dp[n-1] == 1)return 1;
    return 0;
}

