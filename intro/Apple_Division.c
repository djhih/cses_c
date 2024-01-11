#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define int long long
long long a[21], n, ans = 10000000001;
 
void rec(int l, int s1, int s2){
    if(l == n){
        ans = ans<abs(s1-s2)?ans:abs(s1-s2);
        return;
    }
    rec(l+1, s1+a[l], s2);
    rec(l+1, s1, s2+a[l]);
}
signed main(){
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    rec(0, 0, 0);
    printf("%lld\n", ans);
}