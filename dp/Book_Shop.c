#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, x, pr[1024], pa[1024], dp[100005];
int main(){
    // 拿或不拿當前這個，遍歷下去。
    // dp[i] = max(dp[i], dp[i-pr[j]]+pa[j])
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; i++) scanf("%d", &pr[i]);
    for(int i=0; i<n; i++) scanf("%d", &pa[i]);
    for(int i=0; i<n; i++){
        for(int j=x; j>=pr[i]; j--){
            dp[j] = (dp[j]>dp[j-pr[i]]+pa[i]) ? dp[j] : dp[j-pr[i]]+pa[i]; 
        }
    }
    // for(int i=0; i<x; i++) printf("%d ", dp[i]);
    // printf("\n");
    printf("%d", dp[x]);
}