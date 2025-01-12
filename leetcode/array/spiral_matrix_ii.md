# 螺旋矩阵II

[力扣题目链接](https://leetcode.cn/problems/spiral-matrix-ii/)
## 题目
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3

输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

## 思路
**模拟**
1. 创建一个二维数组，长度为n，每个元素都为0，表示初始化一个n*n的二维数组
2. 定义相关变量
- `cs` ： 循环次数
- `index` ： 初始位置索引
- `d` ： 控制每条边遍历的长度
- `num` ： 初始化填充数字
3. 模拟一个游标，从外围一直绕圈到内圈，每次循环都向内移动一位，同时遍历每条边，填充数字
4. 返回二维数组
C++：
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int cs = n / 2;
        int indexx = 0;
        int indexy = 0;
        int d = 1;
        int num = 1;
        while (cs--) {
            int i = indexx, j = indexy;
            while (i < n - d) {
                ans[j][i] = num++;
                i++;
            }
            while (j < n - d) {
                ans[j][i] = num++;
                j++;
            }
            while (i >= d) {
                ans[j][i] = num++;
                i--;
            }
            while (j >= d) {
                ans[j][i] = num++;
                j--;
            }
            d++;
            indexx++, indexy++;
        }
        if (n % 2 != 0) {
            ans[n / 2][n / 2] = num;
        }
        return ans;
    }
};
```
Python:
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n <= 0:
            return []
        ans = [[0] * n for _ in range(n)]
        cs = n // 2
        index = 0
        num = 1
        d = 1
        while cs:
            i = j = index
            while i < n - d:
                ans[j][i] = num
                num += 1
                i += 1
            while j < n - d:
                ans[j][i] = num
                num += 1
                j += 1
            while i >= d:
                ans[j][i] = num
                num += 1
                i -= 1
            while j >= d:
                ans[j][i] = num
                num += 1
                j -= 1
            cs -= 1
            d += 1
            index += 1
        if n % 2 != 0:
            ans[n // 2][n // 2] = num
        return ans
```

 
