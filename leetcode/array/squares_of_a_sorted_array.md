# 有序数组的平方

[力扣题目链接](https://leetcode.cn/problems/squares-of-a-sorted-array/)

## 题目
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
* 输入：nums = [-4,-1,0,3,10]
* 输出：[0,1,9,16,100]
* 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2：
* 输入：nums = [-7,-3,2,3,11]
* 输出：[4,9,9,49,121]
## 思路
定义双指针，一个指向头，一个指向尾，比较两个指针指向的数的平方，将较大的数放入结果数组中，然后移动指针。

C++:
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int index = nums.size() - 1;
        while (i <= j) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[index--] = nums[i] * nums[i];
                i++;
            } else {
                ans[index--] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
};
```

Python:
```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        i, j, pos = 0, n - 1, n - 1
        while i <= j:
            if nums[i] * nums[i] > nums[j] * nums[j]:
                ans[pos] = nums[i] * nums[i]
                i += 1
            else:
                ans[pos] = nums[j] * nums[j]
                j -= 1
            pos -= 1
        return ans
```
