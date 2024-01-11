#include<stdio.h>
#include<stdlib.h>
struct pii { int id, val; };
int n, m, apa[200005], apl[200005], ans;
long long k;
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
    // return *(int*)a - *(int*)b;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++) scanf("%d", &apl[i]); 
    for(int i=0; i<m; i++) scanf("%d", &apa[i]);
    qsort(apl, n, sizeof(int), cmp);
    qsort(apa, m, sizeof(int), cmp);
    for(int i=0, j=0; i<n && j<m; ){
        if(abs(apl[i]-apa[j]) <= k){ // find aparment
            ans++, i++, j++;
        } else {
            if(apl[i]-apa[j] > k) j++; // applicant too big
            else i++; // apparment too big
        }
        // printf("i:%d j:%d ans:%d\n", i, j, ans);
    }
    printf("%d\n", ans);
} 