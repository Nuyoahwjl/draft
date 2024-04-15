#include <stdio.h>

// 函数：找出所有和为 k 的子数组的个数
int countSubarrays(int arr[], int n, int k) {
    int count = 0;
    int sum = 0;

    // 遍历数组，计算以每个元素为起点的子数组的和
    for (int i = 0; i < n; i++) {
        sum = 0;
        // 将当前元素与后续元素相加，直到子数组和大于等于 k 或者到达数组末尾
        for (int j = i; j < n; j++) {
            sum += arr[j];
            // 如果子数组和等于 k，增加计数
            if (sum == k) {
                count++;
                // break;
            }
            // 如果子数组和大于 k，结束内层循环
            // if (sum > k) {
            //     break;
            // }
        }
    }
    return count;
}

int main() {
    // 用户输入数组大小
    int n;
    printf("请输入数组的大小：");
    scanf("%d", &n);

    // 用户输入数组元素
    int arr[n];
    printf("请输入数组元素：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 用户输入 k
    int k;
    printf("请输入 k 的值：");
    scanf("%d", &k);

    // 调用函数找出所有和为 k 的子数组的个数
    int result = countSubarrays(arr, n, k);
    printf("和为 %d 的子数组的个数为: %d\n", k, result);

    return 0;
}







// //数组中又负数
// #include <stdio.h>
// #include <stdlib.h>
// // 函数：找出所有和为 k 的子数组的个数
// int countSubarrays(int arr[], int n, int k) {
//     // 哈希表，用于存储前缀和及其出现的次数
//     int* prefixSum = (int*)calloc(n + 1, sizeof(int));
//     int count = 0;
//     int sum = 0;

//     // 初始化哈希表
//     prefixSum[0] = 1;

//     // 遍历数组，计算当前位置的前缀和，并更新哈希表
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//         // 查找是否存在一个前缀和，其值为 当前前缀和 - k
//         if (sum >= k && prefixSum[sum - k] > 0) {
//             count += prefixSum[sum - k];
//         }
//         prefixSum[sum]++;
//     }

//     free(prefixSum);
//     return count;
// }

// int main() {
//     // 用户输入数组大小
//     int n;
//     printf("请输入数组的大小：");
//     scanf("%d", &n);

//     // 用户输入数组元素
//     int arr[n];
//     printf("请输入数组元素：");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // 用户输入 k
//     int k;
//     printf("请输入 k 的值：");
//     scanf("%d", &k);

//     // 调用函数找出所有和为 k 的子数组的个数
//     int result = countSubarrays(arr, n, k);
//     printf("和为 %d 的子数组的个数为: %d\n", k, result);

//     return 0;
// }
