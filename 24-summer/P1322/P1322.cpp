#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1000000

// 全局指针用于跟踪当前解析位置
const char *ptr;

// 跳过空白字符
void skip_whitespace() {
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
}

// 解析数字，处理正负数
int parse_number() {
    skip_whitespace();
    int sign = 1;
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }
    else if (*ptr == '+') {
        ptr++;
    }
    if (!isdigit(*ptr)) {
        printf("Error: Expected a number\n");
        exit(EXIT_FAILURE);
    }
    int num = 0;
    while (*ptr && isdigit(*ptr)) {
        num = num * 10 + (*ptr - '0');
        ptr++;
    }
    return sign * num;
}

// 解析命令，返回位移值
int parse_command() {
    skip_whitespace();
    int distance = 0;
    if (strncmp(ptr, "FD", 2) == 0) {
        ptr += 2;
        int value = parse_number();
        distance += value;
    }
    else if (strncmp(ptr, "BK", 2) == 0) {
        ptr += 2;
        int value = parse_number();
        distance -= value;
    }
    else if (strncmp(ptr, "REPEAT", 6) == 0) {
        ptr += 6;
        int times = parse_number();
        skip_whitespace();
        if (*ptr != '[') {
            printf("Error: Expected '[' after REPEAT\n");
            exit(EXIT_FAILURE);
        }
        ptr++; // 跳过 '['
        int inner_distance = 0;
        while (*ptr && *ptr != ']') {
            inner_distance += parse_command(); // 递归解析内部命令
            skip_whitespace();
        }
        if (*ptr != ']') {
            printf("Error: Expected ']' after REPEAT block\n");
            exit(EXIT_FAILURE);
        }
        ptr++; // 跳过 ']'
        distance += inner_distance * times;
    }
    else {
        printf("Error: Unknown command\n");
        exit(EXIT_FAILURE);
    }
    return distance;
}

// 解析整个表达式
int parse_expression() {
    int total_distance = 0;
    while (*ptr) {
        total_distance += parse_command();
        skip_whitespace();
    }
    return total_distance;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    // 读取一整行输入
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error: Failed to read input\n");
        return EXIT_FAILURE;
    }
    // 初始化指针
    ptr = input;
    int result = parse_expression();
    // 输出结果的绝对值
    printf("%d\n", abs(result));
    return 0;
}
