#include<stdio.h>
typedef long long int ll;
int n;
ll x, table[1000005];
int main(){
    for(int i=1; i<1000005; i++){
        for(int j=i; j<1000005; j+=i){
            table[j]++;
        }
    }
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld",&x);
        printf("%lld\n",table[x]);
    }
}