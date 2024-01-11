#include <stdio.h>
#define int long long
int n, ans[10010];

void mkTable() {
    for (int i = 4, j = 3; i <= n; i++, j++) {
        ans[i] += ans[j] + j * j - 2 + 2 * (j * j * j - 4 * j + 6) + (2 * j + 1) * (2 * j) / 2 - 2;
    }
}

signed main() {
    scanf("%lld", &n);
    ans[1] = 0, ans[2] = 6, ans[3] = 28;
    mkTable();
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
