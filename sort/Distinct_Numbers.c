#include<stdio.h>
#include<stdlib.h>
long long a[200005];
int cmp(const void *a, const void *b){
    return *(long long *)a - *(long long *)b;
}
int main(){
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp);
    int cur=a[0], cnt=1;
    for(int i=0; i<n; i++){
        if(a[i]!=cur){
            cur = a[i];
            cnt ++;
        }
    }
    printf("%d\n", cnt);
}
// ez sorting