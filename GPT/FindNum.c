/*在数组nums[n]中，数字都是1到n-1范围内的，
其中有且只有一个重复数字，找到它，时间复杂度 O(n), 空间复杂度 O(1)*/


#include <stdio.h>
#include <stdlib.h>
int findDuplicate(int* nums, int numsSize) {
    // 遍历数组
    for (int i = 0; i < numsSize; i++) {
        // 获取对应索引位置的元素
        int index = abs(nums[i]);
        // 检查该位置的元素是否为负值，如果是则表示已经访问过，找到了重复数字
        if (nums[index] < 0) {
            return index;
        }
        // 将访问过的位置的元素取负值
        nums[index] *= -1;
    }
    return -1; // 如果未找到重复数字
}

int main() {
    int nums[] = {1, 3, 4, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int duplicate = findDuplicate(nums, numsSize);
    if (duplicate != -1) {
        printf("重复数字是: %d\n", duplicate);
    } else {
        printf("未找到重复数字\n");
    }
    return 0;
}