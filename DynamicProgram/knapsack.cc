#include<iostream>
using namespace std;

int knapsack01(int* w, int* v, int n, int t){
    int dp[n][t];
    int max = 0;
    for(int i=0; i<n; i++){ //边界条件1
        dp[i][0] = 0;
    }
    for(int i=1; i < t; i++){ //边界条件2
        if(i >= w[0]){
            dp[0][i] = v[0];
            max = v[0];
        }else{
            dp[0][i] = 0;
        }
    }
    for(int i=1; i<n; i++){//状态转移
        for(int j=0; j<=t; j++){
            if(j<w[i]){
                dp[i][j] = dp[i-1][j];
            }else if(dp[i-1][j-w[i]] + v[i] > dp[i-1][j]){
                 dp[i][j] = dp[i-1][j-w[i]] + v[i];
            }else{
                 dp[i][j] = dp[i-1][j];
            }
            if(max < dp[i][j]) max = dp[i][j];
        }
    }
    return max;
}

int knapsack(int* w, int* v, int n, int t){
    int dp[t];
    for(int i=0; i <= t; i++){
        int tmp = 0;
        for(int j=0; j<n; j++){
            if(i >= w[j]){
                if(dp[i-w[j]] + v[j] > tmp) tmp = dp[i-w[j]] + v[j];
            }
        }
        dp[i] = tmp;
        //cout << dp[i] << " ";
    }
    //cout << endl;
    return dp[t];
}


int main(){
    int w[] = {3,8,9,14,6,7,5,3,10};
    int v[] = {7,4,2,10,9,3,5,2,7};
    cout << knapsack01(w,v,9,13) <<endl;
    cout << knapsack(w,v,9,13) <<endl;
}