// #include <iostream>
// #include <string>
// #include <vector>
// #include <sstream>

// using namespace std;

// // 计算表达式的值
// int evaluate_expression(const string& expr) {
//     int sum = 0;
//     stringstream ss(expr);
//     string token;

//     // 按照'+'拆分表达式
//     while (getline(ss, token, '+')) {
//         // 对每个部分进行乘法计算
//         stringstream multiply_stream(token);
//         string num;
//         int product = 1;
//         while (getline(multiply_stream, num, '*')) {
//             product *= stoi(num);
//             product %= 10000; // 避免溢出，乘法后取模
//         }
//         sum += product;
//         sum %= 10000; // 加法后取模，保持结果在最后四位
//     }

//     return sum;
// }

// int main() {
//     string expression;
//     cin >> expression;

//     int result = evaluate_expression(expression);
//     cout << result << endl;

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MOD 10000

int evaluate_expression(const char *expr) {
    int stack[1000000];  // 定义一个足够大的栈
    int top = -1;  // 栈顶指针
    long long num = 0;   // 当前读取的数字
    char op = '+'; // 前一个操作符

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            num = num * 10 + (expr[i] - '0');  // 读取多位数字
        }

        // 如果遇到操作符或到达字符串末尾，处理之前读取的数字
        if (!isdigit(expr[i]) || expr[i+1] == '\0') {
            if (op == '*') {
                stack[top] = (stack[top] * num) % MOD;  // 栈顶元素与当前数字相乘并取模
            } else {
                stack[++top] = num;  // 加法则直接将数字压入栈
            }
            op = expr[i];  // 更新当前操作符
            num = 0;  // 重置当前数字
        }
    }

    // 计算栈中所有元素的和
    int result = 0;
    for (int i = 0; i <= top; i++) {
        result = (result + stack[i]) % MOD;  // 累加并取模
    }

    return result;
}

int main() {
    char expression[1000001];  // 输入表达式的最大长度为100000
    scanf("%s", expression);  // 读取输入的表达式

    int result = evaluate_expression(expression);
    printf("%d\n", result);  // 输出结果的最后四位

    return 0;
}
