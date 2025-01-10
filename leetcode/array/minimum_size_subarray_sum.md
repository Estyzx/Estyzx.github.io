# 长度最小的子数组

[力扣题目链接](https://leetcode.cn/problems/minimum-size-subarray-sum/)
## 题目
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

* 输入：s = 7, nums = [2,3,1,2,4,3]
* 输出：2
* 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

提示：

* 1 <= target <= 10^9
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^5

## 解题思路
**滑动窗口**
1. 创建一个滑动窗口，窗口的左右边界分别为`left`和`right`，初始时`left=right=0`，表示窗口的起始位置。
2. 计算当前窗口的和`sum`，初始时`sum=nums[0]`。
3. 当`sum`小于`target`时，将`right`向右移动一位，更新`sum`和`right`的值。
4. 当`sum`大于等于`target`时，记录当前窗口的长度`right-left+1`，并更新`left`的值，直到`sum`小于`target`。
5. 重复步骤3和步骤4，直到`right`遍历完数组。
6. 如果`right`遍历完数组后没有找到符合条件的子数组，返回0。
> 需要判断数组是否为0

C++:
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int sum = 0;
        int ans = INT_MAX;
        int i = 0, j = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

Python:
```python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if not nums:
            return 0
        left = 0
        right = 0
        sum = 0
        ans = len(nums) + 1
        while right < len(nums):
            sum += nums[right]
            while sum >= target:
                ans = min(ans, right - left + 1)
                sum -= nums[left]
                left += 1
            right += 1
        return 0 if ans == len(nums) + 1 else ans
```
