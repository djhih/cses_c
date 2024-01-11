#include<stdio.h>
struct Pair {
    int first;
    int second;
};
typedef struct Pair Pair;
Pair vec[1000000];
int mov = 0, vec_ptr;
void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        vec[vec_ptr].first = a;
        vec[vec_ptr].second = c;
        vec_ptr++;
        mov++;
        return;
    }

    hanoi(n - 1, a, c, b);
    mov++;
    vec[vec_ptr].first = a;
    vec[vec_ptr].second = c;
    vec_ptr++;
    hanoi(n - 1, b, a, c);
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    printf("%d\n", mov);
    for (int i = 0; i < mov; i++) {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
    return 0;
}
