#include <stdio.h>
#include <string.h>

// 函数用于去除字符串末尾的'0'并反转
void reverse_and_trim(char* s, int start, int end) {
    while (end >= start && s[end] == '0')
        end--;
    if (end < start) {
        printf("0");
        return;
    }
    for (int i = end; i >= start; i--) {
        printf("%c", s[i]);
    }
}

int main() {
    char s[30];
    scanf("%s", s);
    int len = strlen(s);
    if (len == 0) {
        printf("0");
        return 0;
    }

    int flag = 1;
    int pos2 = -1, pos3 = -1;

    // 查找符号位置
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') {
            flag = 2;
            pos2 = i;
            break;
        }
        if (s[i] == '/') {
            flag = 3;
            pos3 = i;
            break;
        }
        if (s[i] == '%') {
            flag = 4;
            break;
        }
    }

    switch (flag) {
        case 1:
            reverse_and_trim(s, 0, len - 1);
            break;
        case 2:
        {
            reverse_and_trim(s, 0, pos2 - 1);
            printf(".");
            int a=pos2+1;
            while(s[a]=='0')
                a++;
            if(a==len)
            {
                printf("0");
                break;
            }
            while(len-1>=a)
            {
                len--;
                printf("%c",s[len]);
            }
            break;
        }
        case 3:
            reverse_and_trim(s, 0, pos3 - 1);
            printf("/");
            reverse_and_trim(s, pos3 + 1, len - 1);
            break;
        case 4:
            reverse_and_trim(s, 0, len - 2);  // len-2是为了去除百分号
            printf("%%");
            break;
        default:
            break;
    }

    return 0;
}
