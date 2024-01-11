#include<stdio.h>
char grp[8][8];
int ways;
 
int check(int row, int col, int line, int left, int right){
    if(grp[row][col] == '*') return 0;
    int res = line | left | right;
    for(int i=0; i<col; i++) res>>=1;
    return !(res&1);
}
 
void count(int row, int line, int left, int right){
    if(row == 7){
        for(int i=0; i<8; i++){
            if(check(row, i, line, left, right)){
                ways++;
            } 
        } 
        return;
    }
    for(int i=0; i<8; i++){
        if(check(row, i, line, left, right)){
            count(row+1, line|(1<<i), (left|(1<<i))<<1, (right|(1<<i))>>1);
        }
    }
    return;
}
 
int main(){
    for(int i=0;i<8;i++) for(int j=0; j<8; j++) scanf(" %c", &grp[i][j]);
    count(0, 0, 0, 0);
    printf("%d\n", ways);
}  