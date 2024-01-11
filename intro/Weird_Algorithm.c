#include <stdio.h>
long long int n;
void f() {
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        printf("%lld ", n);
    }
}

int main() {
    scanf("%lld", &n);
    printf("%lld ", n);
    f();
    printf("\n");
    return 0;
}
