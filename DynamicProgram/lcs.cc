#include<iostream>
using namespace std;

int LCS(char* s1, char* s2, int m, int n){
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] =0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    return dp[m][n];
}

int main(){
    char s1[] = "BDCABAE";
    char s2[] = "ABCBDABFE";
    cout << LCS(s1, s2, 7, 9) << endl;
}