#include<stdio.h>
int dp[1000010], a[1000010];

int main(){
    int n, q, mn=1000001;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
        mn = (mn > a[i] ? a[i] : mn);
    }
    for(int i=0; i<mn; i++){
        dp[i] = 0;
    }
    for(int i=mn; i<=q; i++){
        int mnn = 1000001;
        for(int j=0; j<n; j++){
            if(i-a[j] < 0) continue;
            if(dp[i-a[j]] != 0 || i-a[j] == 0)
                mnn = (mnn > dp[i-a[j]]+1 ? dp[i-a[j]]+1 : mnn);
        }   
        if(mnn != 1000001)
            dp[i] = mnn;
    }
    // for(int i=0; i<q; i++){
    //     printf("%d %lld\n", i, dp[i]);
    // }
    printf("%d\n", (dp[q] == 0 ? -1 : dp[q]));
}