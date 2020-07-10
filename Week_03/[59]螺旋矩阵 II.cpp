//给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
// 示例: 
//
// 输入: 3
//输出:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//] 
// Related Topics 数组 
// 👍 202 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i<n; i++){
            vector<int> row;
            matrix.push_back(row);
            for (int j = 0; j<n; j++){
                matrix[i].push_back(0);
            }
        }
        int begin = 1;
        int loop = n / 2;
        if (n % 2 == 0)loop--;
        for (int i = 0; i <= loop; i++){
            int up = i, down = n - i - 1, right = n - i - 1, left = i;
            int x = left, y = up;
            //right
            for (; x <= right; x++){
                matrix[y][x] = begin++;
            }
            //down
            for (x--,y=y+1; y <= down; y++){
                matrix[y][x] = begin++;
            }
            //left;
            for (y--,x=x-1; x >= left; x--){
                matrix[y][x] = begin++;
            }
            //up
            for (x++,y=y-1; y>up; y--){
                matrix[y][x] = begin++;
            }
        }
        return matrix;
    }
};




//leetcode submit region end(Prohibit modification and deletion)
