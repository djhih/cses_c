#include<stdio.h>
long long a, ans;
int main(){
    scanf("%lld", &a);
    for(int i=5; i<=a; i*=5){
        ans += a/i;
    }
    printf("%lld\n", ans);
}