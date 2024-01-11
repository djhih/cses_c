#include <stdio.h>
#include <string.h>

#define T 1010
#define N 2000100

char s[N];

int main() {
    scanf("%s", s);
    int len = strlen(s), cnt = 0, mx = 0;
    char now = s[0];

    for (int i = 0; i < len; i++) {
        if (now == s[i]) {
            cnt++;
            if (cnt > mx) mx = cnt;
        } else {
            now = s[i];
            cnt = 1;
        }
    }

    printf("%d\n", mx);
    return 0;
}
