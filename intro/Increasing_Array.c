#include <stdio.h>
#define int long long
int n, a[200005], t[200005];

int lowbit(int x) {
    return x & (-x);
}

signed main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int now = a[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < now) {
            int dif = (now - a[i]);
            a[i] += dif;
            ans += dif;
        }
        now = a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
