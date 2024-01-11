#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
const int mod = 1e9+7;
int n, m, a[100005];
ll dp[100005][128];
int main(){
    // dp[i][c] 在第 i 個空間為 c 的情況下最多的可能數
    // dp[i][c] = dp[i-1][c] + dp[i-1][c+1] + dp[i-1][c-1]
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++){
        if(i == 0){ // 每個數都可能
            if(a[i] == 0) for(int j=1; j<=m; j++) dp[0][j] = 1;
            else dp[0][a[i]] = 1;
        } else if(a[i] == 0){
            for(int j=1; j<=m; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1]) % mod;
            }
        } else {
            dp[i][a[i]] = (dp[i-1][a[i]] + dp[i-1][a[i]+1] + dp[i-1][a[i]-1]) % mod;
        } 
    }
    ll ans = 0;
    for(int i=1; i<=m; i++) ans = (ans + dp[n-1][i]) % mod;
    printf("%lld\n", ans);
}