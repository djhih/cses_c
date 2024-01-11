#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
const int mod = 1e9+7;
int t, n;
ll dp[1000005][2];
int main(){
    // 聚焦在當前高度的最上層
    // 先將最上層分成左右討論，單邊有兩種選擇，上下相連或否，還要考慮下層是否相連的情況
    // 再考慮左右相連的情況，也可以選擇是否與下面一層相連
    // dp[i][0] 在 i 高度，第 i 層分開，最多的組合數
    // dp[i][1] 在 i 高度，第 i 層左右相連，最多的組合數
    // dp[i][0]= dp[i-1][1] + 4*(dp[i-1][0] 
    // dp[i][1] = 2*dp[i-1][1] + dp[i-1][0]
    
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= 1000000; i++){
        dp[i][0] = dp[i-1][1] + 4*(dp[i-1][0] % mod);
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % mod;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", (dp[n][0] + dp[n][1]) % mod);
    }
}