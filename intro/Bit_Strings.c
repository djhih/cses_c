#include <stdio.h>

int main() {
    long long a, ans = 2;
    scanf("%lld", &a);
    for (int i = 0; i < a - 1; i++) {
        ans *= 2;
        ans %= 1000000007;
    }
    printf("%lld\n", ans);
    return 0;
}
