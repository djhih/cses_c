#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[1000005];
int main(){
    int n;
    scanf("%d",&n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j>0; j/=10){
            // 每一位來自上一層的數字減某一個數字
            dp[i] = (dp[i] > dp[i-j%10]+1 ? dp[i-j%10]+1 : dp[i]);
        }
    }
	printf("%d",dp[n]);
}