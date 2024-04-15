/*给定一个数组，出一个具有最大和的连续子数组（子数组最少包含一个元素），操作结果是其最大和*/

#include <stdio.h>
int maxSubArray(int* nums, int numsSize) {
    // 初始化最大和和当前子数组的和为数组的第一个元素
    int max_sum = nums[0];
    int current_sum = nums[0];
    // 从数组的第二个元素开始遍历
    for (int i = 1; i < numsSize; i++) {
        // 更新当前子数组的和，使其为当前元素值与当前元素值与前一个子数组的和中的较大值
        current_sum = (current_sum + nums[i] > nums[i]) ? current_sum + nums[i] : nums[i];
        // 更新最大和，使其为当前子数组的和和最大和中的较大值
        max_sum = (current_sum > max_sum) ? current_sum : max_sum;
    }
    return max_sum;
}

int main() {
    // 测试数组
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // 数组大小
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    // 调用函数找出最大和
    int result = maxSubArray(nums, numsSize);
    // 打印结果
    printf("最大和为: %d\n", result);
    return 0;
}

