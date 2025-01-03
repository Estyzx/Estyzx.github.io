# 二分查找


[力扣题目链接](https://leetcode.cn/problems/binary-search/)

## 题目
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:        

```
输入: nums = [-1,0,3,5,9,12], target = 9     
输出: 4       
解释: 9 出现在 nums 中并且下标为 4     
```

示例 2:    

```
输入: nums = [-1,0,3,5,9,12], target = 2     
输出: -1        
解释: 2 不存在 nums 中因此返回 -1        
```

提示：    

* 你可以假设 nums 中的所有元素是不重复的。
* n 将在 [1, 10000]之间。
* nums 的每个元素都将在 [-9999, 9999]之间。

## 思路
由于题目给定了**数组有序**，且**无重复数据**，所以可以使用二分查找。

## 二分模板

C++:
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (j + i)>>1;
            if (nums[mid] >= target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return i < nums.size() && nums[i] == target ? i : -1;
    }
};
```

Python3:

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1
        while i <= j:
            mid = (i + j) // 2
            if nums[mid] >= target:
                j = mid - 1
            else:
                i = mid + 1
        return i if i < len(nums) and nums[i] == target else -1
```