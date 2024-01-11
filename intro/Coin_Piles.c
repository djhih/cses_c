#include<stdio.h>
int main(){
    int t, b, a;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }
        if((2*b-a)%3==0 && (2*b-a)/3 <= a){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}