#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[5050], ss[5050];
int dp[5050][5050];
int minn(int a, int b){
    return a<b?a:b;
}
int main(){
    // dp[i][j] 表示 string 1 長度為 i，string 2 長度為 j 的最小編輯距離
    // dp[i][j] = dp[i-1][j-1] if s[i-1] == ss[j-1]
    // dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1) if s[i-1] != ss[j-1]
    scanf("%s %s", s, ss);
    int n = strlen(s), m = strlen(ss);
    for (int i=0; i<=n; i++){
        dp[i][0] = i;
    }
    for (int i=0; i<=m; i++){
        dp[0][i] = i;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1] == ss[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = minn(dp[i-1][j-1]+1, minn(dp[i-1][j]+1, dp[i][j-1]+1));
        }
    }
    printf("%d\n", dp[n][m]);
}