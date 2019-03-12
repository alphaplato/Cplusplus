#include <iostream>
using namespace std;

int LCSS(char* s1, char* s2, int n, int m){
    int dp[n+1][m+1];
    int max = 0;
    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<m+1; j++){
        dp[0][j] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return max;
}

int main(){
    char s1[] = "abcadabcdg";
    char s2[] = "bcabcdf";
    cout << LCSS(s1, s2, 10, 7) << endl;
    return 0;
}