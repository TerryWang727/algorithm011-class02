//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Mar
//cos 贡献此图。 
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // left[i]表示i左边的最大值，right[i]表示i右边的最大值
        vector<int> left(n), right(n);
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        int water = 0;
        for (int i = 0; i < n; i++) {
            int level = min(left[i], right[i]);
            water += max(0, level - height[i]);
        }
        return water;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
