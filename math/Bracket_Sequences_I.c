#include <stdio.h>
#define int long long
const int md = 1000000007;
const int N = 2000006;
int F[2000006], I[2000006];
int poww(int x, int y) {
    int ret = 1;
    x = x % md;
    for(; y; y >>= 1, x = (x * x) % md){
        if(y & 1) ret = (ret * x) % md;
    }
    return ret;
}

signed main() {
    // catalan
    // https://zh.wikipedia.org/zh-tw/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
    // (2𝑛¦𝑛) − (2𝑛¦(𝑛+1)) = 1/(𝑛+1) (2𝑛¦𝑛)
    // (2𝑛¦𝑛)代表全部可能， (2𝑛¦(𝑛+1))為非法可能。
    
    int n;
    scanf("%lld", &n);
    if (n & 1) {
        printf("0\n");
        return 0;
    }
    n >>= 1;
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < N; i++) {
        F[i] = (F[i - 1] * i) % md;
        I[i] = poww(F[i], md - 2);
    }
    int ans = (F[2 * n] * I[n]) % md;
    ans = (ans * I[n]) % md;
    ans = (ans * poww(n + 1, md - 2)) % md;
    printf("%lld\n", ans);
    return 0;
}
