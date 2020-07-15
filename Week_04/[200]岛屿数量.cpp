//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1: 
//
// 输入:
//[
//['1','1','1','1','0'],
//['1','1','0','1','0'],
//['1','1','0','0','0'],
//['0','0','0','0','0']
//]
//输出: 1
// 
//
// 示例 2: 
//
// 输入:
//[
//['1','1','0','0','0'],
//['1','1','0','0','0'],
//['0','0','1','0','0'],
//['0','0','0','1','1']
//]
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 652 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int counter = 0;
//        for (int i = 0; i < grid.size(); ++i)
//            for (int j = 0; j < grid.size(); ++j)
//                if (grid[i][j] == '1') {
//                    ++counter;
//                    DFS(grid, i, j);
//                }
//        return counter;
//    }
//    void DFS(vector<vector<char>>& grid, int i, int j) {
//        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size()) return;
//        if (grid[i][j] == '0') return;
//        grid[i][j] = '0';
//        DFS(grid, i-1, j);
//        DFS(grid, i+1, j);
//        DFS(grid, i, j-1);
//        DFS(grid, i, j+1);
//    }
//};

//class Solution {
//public:
//    void findIsland(vector<vector<char>>& grid,int row,int col,int rowsize,int colsize)
//    {
//        if(row<0||row >= rowsize||col <0 || col >= colsize|| grid[row][col]=='0')
//        {
//            return;
//        }
//        else
//        {
//            grid[row][col] = '0';
//            findIsland(grid,row-1,col,rowsize,colsize);
//            findIsland(grid,row+1,col,rowsize,colsize);
//            findIsland(grid,row,col-1,rowsize,colsize);
//            findIsland(grid,row,col+1,rowsize,colsize);
//        }
//    }
//
//    int numIslands(vector<vector<char>>& grid) {
//        if(grid.empty()) return 0;
//
//        int rowsize = grid.size();
//        int colsize = grid[0].size();
//
//        int i,j,res=0;
//        for(i=0;i<rowsize;i++)
//        {
//            for(j=0;j<colsize;j++)
//            {
//                // cout<< grid[i][j] <<endl;
//                if(grid[i][j]=='1')
//                {
//                    res++;
//                    findIsland(grid,i,j,rowsize,colsize);
//
//                }
//            }
//        }
//        return res;
//    }
//};



class Solution {
public:
    void findIsland(vector<vector<char>>& grid,int row,int col,int rowsize,int colsize)
    {
        if(row<0||row >= rowsize||col <0 || col >= colsize|| grid[row][col]=='0')
        {
            return;
        }
        else
        {
            grid[row][col] = '0';
            findIsland(grid,row-1,col,rowsize,colsize);
            findIsland(grid,row+1,col,rowsize,colsize);
            findIsland(grid,row,col-1,rowsize,colsize);
            findIsland(grid,row,col+1,rowsize,colsize);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int rowsize = grid.size();
        int colsize = grid[0].size();

        int i,j,res=0;
        for(i=0;i<rowsize;i++)
        {
            for(j=0;j<colsize;j++)
            {
                // cout<< grid[i][j] <<endl;
                if(grid[i][j]=='1')
                {
                    res++;
                    findIsland(grid,i,j,rowsize,colsize);

                }
            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
