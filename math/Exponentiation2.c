#include<stdio.h>
typedef long long int ll;
ll mod = 1e9+7;
ll poww(ll a, ll b, ll mdd){
    long long int bs = a, res = 1;
    for(; b; b>>=1, bs*=bs, bs%=mdd){
        if(b&1) res = (res*bs)%mdd;
        res = res%mdd;
    }
    return res;
}
int main(){
    // fermat fomular a^(p-1) = 1 (mod p), get b^c mod p-1, then get a^b^c mod p-1
    int n, a, b, c;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &a, &b, &c);
        ll res1 = poww(b, c, mod-1);
        printf("%lld\n", poww(a, res1, mod));        
    }
}