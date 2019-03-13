#include <iostream>
using namespace std;

int LIS(char* s, int n){
    if(n==0){
        return 0;
    }
    int dp[n];
    int max = 1;
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(s[i] > s[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}

int main(){
    char s[]="ABCBDCFDEG";
    cout << LIS(s,10) << endl;
    return 0;
}