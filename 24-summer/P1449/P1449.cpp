//不考虑负数
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[50];
int top = 0;

void push(int x) {
    stack[top++] = x;
}
int pop(void) {
    return stack[--top];
}

int main() {
    int num, temp;
    char c;
    
    while ((c = getchar()) != '@') {
        if (isdigit(c)) {  // 检测到数字
            num = 0;
            do {
                num = num * 10 + c - '0';
                c = getchar();
            } while (c != '.');
            push(num);  // 转化为十进制整数并入栈
        // } else if (c == '-') {
        //     c = getchar();
        //     if (isdigit(c)) {  // 若‘-’后为数字，则表示一个负数
        //         num = 0;
        //         do {
        //             num = num * 10 + c - '0';
        //             c = getchar();
        //         } while (c != '.');
        //         push(-num);
        //     } else {  // 否则表示减号, 执行相减操作
        //         temp = pop();
        //         push(pop() - temp);
        //         ungetc(c, stdin);  // 将读到的字符放回输入流
        //     }
        } else if (isgraph(c)) {  // 检测到除数字和‘-’外的其他非空格字符
            switch (c) {
                case '+': push(pop() + pop()); break;
                case '-': temp=pop();
                          push(pop()-temp);
                          break;
                case '*': push(pop() * pop()); break;
                case '/': temp = pop();
                          push(pop() / temp);
                          break;
            }
        }
    }
    printf("%d", pop());
    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// int evaluatePostfix(const char* s) {
//     int stack[50];  // 栈用于保存操作数
//     int top = -1;   // 栈顶指针

//     for (int i = 0; s[i] != '@'; i++) {
//         if (isdigit(s[i])) {
//             int num = 0;
//             while (s[i] != '.') {
//                 num = num * 10 + (s[i] - '0');
//                 i++;
//             }
//             stack[++top] = num;  // 将操作数压入栈
//         } else {
//             int b = stack[top--];  // 弹出栈顶的操作数
//             int a = stack[top--];  // 弹出次顶的操作数

//             switch (s[i]) {
//                 case '+': stack[++top] = a + b; break;
//                 case '-': stack[++top] = a - b; break;
//                 case '*': stack[++top] = a * b; break;
//                 case '/': stack[++top] = a / b; break;  // 向0取整与C/C++相同
//             }
//         }
//     }

//     return stack[top];  // 栈中最后剩下的元素就是结果
// }

// int main() {
//     char s[51];
//     scanf("%s", s);
//     int result = evaluatePostfix(s);
//     printf("%d\n", result);
//     return 0;
// }
