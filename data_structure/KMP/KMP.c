#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0; // 长度为0的最长相等前缀和后缀
    int i = 1;

    lps[0] = 0; // lps[0]固定为0

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M]; // 部分匹配表

    computeLPSArray(pattern, M, lps);

    int i = 0; // text中的当前位置
    int j = 0; // pattern中的当前位置

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    // char text[] = "ABABDABACDABABCABAB";
    // char pattern[] = "ABABCABAB";

    char text[20];
    char pattern[20];
    scanf("%s",text);
    scanf("%s",pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Matching positions:\n");
    KMPSearch(text, pattern);

    return 0;
}
