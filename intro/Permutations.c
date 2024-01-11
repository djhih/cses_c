#include <stdio.h>
#define int long long
int n, a[1000006], t[1000006];

int lowbit(int x) {
    return x & (-x);
}

signed main() {
    scanf("%lld", &n);
    if (n == 1) printf("1\n");
    else if (n == 4) printf("2 4 1 3\n");
    else if (n < 5) printf("NO SOLUTION\n");
    else if (n == 5) printf("4 2 5 3 1\n");
    else {
        if (n % 2) {
            printf("%lld ", n);
            for (int i = 1; i <= n / 2; i++) {
                printf("%lld %lld%c", i, i + (n / 2), (i == (n / 2) ? '\n' : ' '));
            }
        }
        else {
            for (int i = 1; i <= n / 2; i++) {
                printf("%lld %lld%c", i, i + (n / 2), (i == (n / 2) ? '\n' : ' '));
            }
        }
    }
    return 0;
}
