#include<stdio.h>
long long mod = 1e9+7;
int main(){
    int n, a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        long long int bs = a, res = 1;
        for(; b; b>>=1, bs*=bs, bs%=mod){
            if(b&1) res = (res*bs)%mod;
            res = res%mod;
        }
        printf("%d\n", res);
    }
}