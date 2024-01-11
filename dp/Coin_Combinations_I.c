#include <stdio.h>
#include <string.h>
#define MAX_N 1000005
#define MOD 1000000007
typedef long long ll;
ll dp[MAX_N];
void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    int v[MAX_N];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - v[j] >= 0) {
                dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
            }
        }
    }
    printf("%lld\n", dp[x]);
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
