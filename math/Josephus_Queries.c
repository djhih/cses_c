#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long ll;

int rec(ll n, ll k){
    if(n ==  1) return 1;
    if(k <= (n+1)/2){ // n+1 is for the case when n is odd
        if(k*2 > n) return (2*k)%n; 
        return 2*k; // n should not be mod to 0
    }
    int tmp = rec(n/2, k - (n+1)/2); // next layer
    if(n%2) return 2*tmp+1; // return to this layer
    return 2*tmp-1;
}
int main(){
    int q, n, k;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &n, &k);
        printf("%d\n", rec(n, k));
    }
}