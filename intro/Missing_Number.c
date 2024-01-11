#include <stdio.h>
#include <stdlib.h>
#define N 200010
typedef long long int ll;
ll n, a[N];
int flg = 0;

int cmp(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &a[i]);
    }
    qsort(a, n - 1, sizeof(ll), cmp);
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 1) {
            printf("%lld\n", a[i] + 1);
            flg = 1;
        }
    }
    if (n == 2) {
        if (a[0] == 1) printf("2\n");
        if (a[0] == 2) printf("1\n");
    }
    if (!flg && n != 2) printf("%lld\n", n);
    return 0;
}
