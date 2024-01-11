#include<stdio.h>
typedef long long ll;
ll fac[1000001];
ll mod = 1000000007;
ll n, a, b, ans;
ll inverse(ll i){ // mod inverse template
    if(i == 1) return 1;
    return (mod - ((mod/i)*inverse(mod%i))%mod + mod)%mod;
}
int main(){
    // \frac{a!}{b!(a-b)!}
    fac[0]=1, fac[1]=1;
    for(int i=2; i<=1000000; i++) fac[i] = (fac[i-1]*i)%mod;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &a, &b);
        ans = (fac[a] * inverse(fac[b]))%mod;
        ans = (ans * inverse(fac[a-b]))%mod;
        printf("%lld\n", ans);
    }
}