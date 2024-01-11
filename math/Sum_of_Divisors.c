#include<stdio.h>
#include<math.h>
typedef long long int ll;
const int mod=1e9+7;
ll n, ans;
ll inverse(ll i){ // mod inverse template
    if(i == 1) return 1;
    return (mod - ((mod/i)*inverse(mod%i))%mod + mod)%mod;
}
int main(){
    scanf("%lld",&n);
    for(ll i=1; i*i<=n; i++){
        ans = (ans + (n/i)*i)%mod;
    }
    ll l = sqrt(n);
    for(ll i=l; i>0; i--){
        ll r = (n/i)%mod;
        ll sum = 0;
        sum = (sum + ((r*(r+1))%mod)*inverse(2)) % mod; // r*(r+1)/2
        sum = (sum - ((l*(l+1))%mod)*inverse(2)) % mod; // l*(l+1)/2
        sum = (sum + mod)%mod; // for negative number
        sum = (sum * i)%mod;
        l = r % mod;
        ans = (ans + sum)%mod;
    }
    printf("%lld\n", ans);
}