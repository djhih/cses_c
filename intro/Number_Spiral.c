#include <stdio.h>
#define int long long
int t, x, y;
signed main() {
    scanf("%lld", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &x, &y);
        if (x >= y) {
            if (!(x % 2)) {
                printf("%lld\n", x * x - y + 1);
            }
            else {
                x--;
                printf("%lld\n", x * x + y);
                x++;
            }
        }
        else {
            if (y % 2) {
                printf("%lld\n", y * y - x + 1);
            }
            else {
                y--;
                printf("%lld\n", y * y + x);
                y++;
            }
        }
    }
    return 0;
}
