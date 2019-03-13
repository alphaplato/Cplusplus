#include <iostream>
using namespace std;

int levenshteinDistance(char* s1, char* s2, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        dp[i][0] = i;
    }
    for(int j=0; j<n+1; j++){
        dp[0][j] = j;
    }
    for(int i=1; i<m+1; i++){
        int temp = INT_MAX;
        for(int j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = dp[i][j-1] + 1 < dp[i-1][j] + 1 ? 
                dp[i][j-1] + 1 : dp[i-1][j] + 1;
            dp[i][j] = dp[i][j] < dp[i-1][j-1] + 1 ?
                dp[i][j] : dp[i-1][j-1] + 1;
        }
    }
    return dp[m][n];
}

int main(){
    char s1[] = "sitting";
    char s2[] = "kitten";
    cout << levenshteinDistance(s1, s2, 7, 6) << endl;
    return 0;
}