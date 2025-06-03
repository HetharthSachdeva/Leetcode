class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        string ans = "";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } 
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int x = n, y = m;
        while(ans.size()<dp[n][m]){
            if(str1[x-1]==str2[y-1]){
                ans = str1[x-1]+ans;
                x--;
                y--;
            }
            else{
                if(dp[x-1][y]>dp[x][y-1]) x--;
                else y--;
            }
        }
        int i = 0, j = 0, k= 0;
        string ans2 = "";
        while(i < n && k < m){
            if(j >= ans.size()){
                while(i < n){
                    ans2+=str1[i++];
                }
                while(k < m){
                    ans2+=str2[k++];
                }
                break;
            }
            else if(str1[i]!=ans[j]){ 
                ans2+=str1[i++];
                
            }    
            else if(str2[k]!=ans[j]){
                ans2+=str2[k++];
                
            }
            else{
                ans2+=ans[j++];
                i++;
                k++;
            }
        }
        while(i < n){
                    ans2+=str1[i++];
                }
                while(k < m){
                    ans2+=str2[k++];
                }
        return ans2;

    }
};