//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。 
//
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。 
//
// 
//
// 例如，给定三角形： 
//
// [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
// 
//
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。 
//
// 
//
// 说明： 
//
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。 
// Related Topics 数组 动态规划 
// 👍 485 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        int n = triangle.size();
//        vector<int> f(n);
//        f[0] = triangle[0][0];
//        for (int i = 1; i < n; ++i) {
//            f[i] = f[i - 1] + triangle[i][i];
//            for (int j = i - 1; j > 0; --j) {
//                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
//            }
//            f[0] += triangle[i][0];
//        }
//        return *min_element(f.begin(), f.end());
//    }
//};


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};

//leetcode submit region end(Prohibit modification and deletion)
