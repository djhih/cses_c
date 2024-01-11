#include<stdio.h>
typedef long long ll;
int n, a[200005];
ll cnt[1000005];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for(int i=1000000; i>=0; i--){
        ll d = 0;     
        for(int j=i; j<=1000000; j+=i){
            d += cnt[j];
        }
        if(d > 1){ // d = 1, the divisor is i, so we don't need to print it.
            printf("%d\n", i);
            return 0;
        }
    }
}