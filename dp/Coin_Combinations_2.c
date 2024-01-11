#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000005
#define MOD 1000000007
typedef long long ll;
ll *dp;
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    qsort(v, n, sizeof(int), compare);
    dp = (ll *)malloc((x + 1) * sizeof(ll));
    memset(dp, 0, (x + 1) * sizeof(ll));
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j - v[i] >= 0) {
                dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
            }
        }
    }
    printf("%lld\n", dp[x]);
    free(v);
    free(dp);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
