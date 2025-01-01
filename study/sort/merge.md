# 归并排序

## 简介
归并排序（Merge Sort）是一种高效的排序算法，采用分治法（Divide and Conquer） 的思想。它的核心步骤是将数组递归地分成两半，分别排序，然后将排序后的两部分合并成一个有序数组。

## 算法步骤
归并排序的步骤如下：
1. 分割：将数组对半分开，直到最小
2. 排序：对每个子数组进行排序
3. 合并：将排序后的子数组合并成一个有序数组

### 分割

```cpp
void mergeSort(vector<int>& nums, int left, int right){

    // 递归终止条件
    if(left >= right){
        return ;
    }

    // 找到中间位置
    int mid = (right + left) >> 1;

    // 对分割的两个子数组进行递归分割
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // 合并两个子数组
    merge(nums, left, mid, right);
}
```

### 排序合并
```cpp
void merge(vector<int>& nums, int left, int mid, int right){

    // 创建临时数组，存储排序后的结果
    vector<int> temp(right - left + 1);

    // 初始化两个指针（i，j），分别指向两个子数组的起始位置
    // k 指向临时数组的起始位置
    int i = left, j = mid + 1, k = 0;

    // 循环比较两个子数组的元素，将较小的元素放入临时数组
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }

    // 将剩余的元素拷贝到临时数组
    while(i <= mid){
        temp[k++] = nums[i++];
    }
    while(j <= right){
        temp[k++] = nums[j++];
    }

    // 将临时数组的元素拷贝回原数组
    for(int i = 0; i < temp.size(); i++){
        nums[left + i] = temp[i];
    }
}
```

## 时间复杂度

归并排序的时间复杂度为 `O(nlogn)`，其中 n 是数组的长度。

## 空间复杂度
归并排序的空间复杂度为 `O(n)`，其中 n 是数组的长度。


## 代码实现
[实现代码](./merge_sort.cpp)