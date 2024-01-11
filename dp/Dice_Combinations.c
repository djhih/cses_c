#include<stdio.h>
long long n, dp[1000010];
const long long mod=1000000007;
int main(){
    dp[0]=1;
    scanf("%lld", &n);
    for(int i=1; i<=n; i++){
        if(i-1>=0) dp[i]+=dp[i-1];
        dp[i] %= mod;
        if(i-2>=0) dp[i]+=dp[i-2];
        dp[i] %= mod;
        if(i-3>=0) dp[i]+=dp[i-3];
        dp[i] %= mod;
        if(i-4>=0) dp[i]+=dp[i-4];
        dp[i] %= mod;
        if(i-5>=0) dp[i]+=dp[i-5];
        dp[i] %= mod;
        if(i-6>=0) dp[i]+=dp[i-6];
        dp[i] %= mod;
    }
    printf("%lld\n", dp[n]);
}
