class Solution {
    private:
        int m,n;
public:
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        
        int res = helperSolve(text1,text2);
        return res;
    }
    
    int helperSolve(string &text1, string &text2){
        vector<vector<int> > dp(m + 1,vector<int>(n + 1, 0));
        
        dp[0][0] = 0;
        for(int i = 1; i < m; ++i){
            dp[i][0] = 0;
        }
        
        for(int j = 1; j < n; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};