# 选择排序

## 简介
选择排序（Selection Sort） 是一种简单直观的排序算法。它的基本思想是：每次从未排序的部分中选择最小（或最大）的元素，将其放到已排序部分的末尾。

## 算法步骤
1. 初始状态：将整个数组分为已排序部分和未排序部分。初始时，已排序部分为空，未排序部分为整个数组。
2. 选择最小元素：在未排序部分中找到最小的元素。
3. 交换位置：将最小元素与未排序部分的第一个元素交换位置。
4. 更新已排序部分：将未排序部分的第一个元素归入已排序部分。
5. 重复：重复上述步骤，直到未排序部分为空。

```cpp
void selectionSort(vector<int>& nums){

    // 定义未排序部分的起始索引
    int index = 0;

    // 循环遍历未排序部分
    while (index < nums.size()) {

        // 定义最小元素的索引
        int minindex = index;

        // 循环遍历未排序部分，找到最小元素的索引
        for (int i = index + 1; i < nums.size(); i++) {

            //  如果找到更小的元素，更新最小元素的索引
            if (nums[i] < nums[minindex]) {
                minindex = i;
            }
        }

        // 将最小元素与未排序部分的第一个元素交换位置
        swap(nums[index], nums[minindex]);

        // 更新已排序部分的起始索引
        index++;
    }
}
```

## 时间复杂度

时间复杂度：`O(n^2)`

## 空间复杂度

空间复杂度：`O(1)`

## 代码实现
[selection.cpp](./selection_sort.cpp)

[selection.py](./selection_sort.py)
