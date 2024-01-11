#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int mod = 1e9+7;
int dp[1024][1024];
char gra[1024][1024];
int main(){
    // 從左邊或上面來的才加，因為方向是從左上到右下
    int n;
    scanf("%d ",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%c", &gra[i][j]);
        } 
        scanf("\n"); // 玄學
    } 
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++){
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(gra[i][j] == '*') dp[i][j] = 0;
            else if (i == 1) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            else if (j == 1) dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            else {
                dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
                dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            }
        }
    }
    printf("%d\n", dp[n][n]);
}