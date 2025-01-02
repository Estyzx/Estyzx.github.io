# 快速排序

## 介绍
快速排序（Quick Sort）是一种基于分治策略的高效排序算法，由Tony Hoare于1959年提出。其核心思想是通过一趟扫描将待排序数组分为两部分，一部分包含小于基准值的元素，另一部分包含大于基准值的元素，然后递归地对这两部分进行排序，直到整个数组有序


## 算法步骤
1. 选择基准数：从待排序数组中任意选择一个元素作为基准数，通常选择第一个元素。
2. 分割：将待排序数组分为两个子数组，一个包含所有小于基准数的元素，另一个包含所有大于基准数的元素。
3. 递归：对小于基准数的子数组和大于基准数的子数组进行递归排序。

```cpp
void quick_sort(vector<int> &nums, int l, int r) {

    // 递归终止条件
    if (l >= r) return;

    // 选择基准数
    int pivot = nums[l];

    // 双指针
    int i = l + 1, j = r;

    while (i <= j) {

        // 注意先从右边开始比较
        while (i <= j && nums[j] > pivot) {
            j--;
        }
        while (i <= j && nums[i] < pivot) {
            i++;
        }

        // 如果i<=j，交换i和j指向的元素
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    // 基准数与当前数进行交换
    swap(nums[l], nums[i - 1]);

    // 递归
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i, r);
}
```

## 时间复杂度
时间复杂度：O(nlogn)

## 空间复杂度
空间复杂度：O(logn)

## 代码实现
[quick.cpp](./quick_sort.cpp)

[quick.py](./quick_sort.py)
