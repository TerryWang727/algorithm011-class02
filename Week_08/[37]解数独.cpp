//编写一个程序，通过已填充的空格来解决数独问题。 
//
// 一个数独的解法需遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 空白格用 '.' 表示。 
//
// 
//
// 一个数独。 
//
// 
//
// 答案被标成红色。 
//
// Note: 
//
// 
// 给定的数独序列只包含数字 1-9 和字符 '.' 。 
// 你可以假设给定的数独只有唯一解。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 回溯算法 
// 👍 487 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    bool col[10][10],row[10][10],f[10][10];
//    bool flag = false;
//    void solveSudoku(vector<vector<char>>& board) {
//        memset(col,false,sizeof(col));
//        memset(row,false,sizeof(row));
//        memset(f,false,sizeof(f));
//        for(int i = 0; i < 9;i++){
//            for(int j = 0; j < 9;j++){
//                if(board[i][j] == '.')   continue;
//                int temp = 3*(i/3)+j/3;
//                int num = board[i][j]-'0';
//                col[j][num] = row[i][num] = f[temp][num] = true;
//            }
//        }
//        dfs(board,0,0);
//    }
//    void dfs(vector<vector<char>>& board,int i,int j){
//        if(flag == true)  return ;
//        if(i >= 9){
//            flag = true;
//            return ;
//        }
//        if(board[i][j] != '.'){
//            if(j < 8)  dfs(board,i,j+1);
//            else dfs(board,i+1,0);
//            if(flag)  return;
//        }
//
//        else{
//            int temp = 3*(i/3)+j/3;
//            for(int n = 1; n <= 9; n++){
//                if(!col[j][n] && !row[i][n] && !f[temp][n]){
//                    board[i][j] = n + '0';
//                    col[j][n] = row[i][n] = f[temp][n] = true;
//                    if(j < 8)  dfs(board,i,j+1);
//                    else dfs(board,i+1,0);
//                    col[j][n] = row[i][n] = f[temp][n] = false;
//                    if(flag)  return;
//                }
//            }
//            board[i][j] = '.';
//        }
//    }
//};

class Solution {
public:

    int row[9][9] = {0};
    int col[9][9] = {0};
    int block[9][9] = {0};

    bool backTrack(vector<vector<char>>& board, int r ,int c) {
        if (r > 8) {
            return true;
        }
        if (board[r][c] == '.') {
            for (char ch = '1'; ch <= '9'; ++ch) {
                if (row[r][ch - '1'] == 1 || col[c][ch - '1'] == 1 || block[r / 3 * 3 + c / 3][ch - '1'] == 1) {
                    continue;
                }
                board[r][c] = ch;
                row[r][ch - '1'] = 1;
                col[c][ch - '1'] = 1;
                block[r / 3 * 3 + c / 3][ch - '1'] = 1;
                if (backTrack(board, r + (c + 1) / 9,(c + 1) % 9)) {
                    return true;
                }
                board[r][c] = '.';
                row[r][ch - '1'] = 0;
                col[c][ch - '1'] = 0;
                block[r / 3 * 3 + c / 3][ch - '1'] = 0;
            }
        }
        else
            return backTrack(board,r + (c + 1) / 9,(c + 1) % 9);
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = 1;
                    col[j][board[i][j] - '1'] = 1;
                    block[i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
                }
            }
        }
        backTrack(board, 0, 0);
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
