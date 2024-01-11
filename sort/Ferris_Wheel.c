#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long n, k, a[200005], ans;
int cmp(const void *a, const void *b){
    return *(long long *)a - *(long long *)b;
}
int main(){
    scanf("%lld%lld", &n, &k);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp);
    int i=0, j=n-1;
    for(; i<j;){
        if(a[i]+a[j] <= k){
            // printf("match a[%d] %d and a[%d] %d\n", i, a[i], j, a[j]);
            i++;
            j--;
            ans++;
        } else {
            j--;
            ans++;
        }
        // printf("a[%d] %d a[%d] %d ans %d\n", i, a[i], j, a[j], ans);
    }
    if(i==j) ans++;
    printf("%lld\n", ans);
}