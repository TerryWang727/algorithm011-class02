//机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令： 
//
// 
// -2：向左转 90 度 
// -1：向右转 90 度 
// 1 <= x <= 9：向前移动 x 个单位长度 
// 
//
// 在网格上有一些格子被视为障碍物。 
//
// 第 i 个障碍物位于网格点 (obstacles[i][0], obstacles[i][1]) 
//
// 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。 
//
// 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。 
//
// 
//
// 示例 1： 
//
// 输入: commands = [4,-1,3], obstacles = []
//输出: 25
//解释: 机器人将会到达 (3, 4)
// 
//
// 示例 2： 
//
// 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
//输出: 65
//解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
// 
//
// 
//
// 提示： 
//
// 
// 0 <= commands.length <= 10000 
// 0 <= obstacles.length <= 10000 
// -30000 <= obstacle[i][0] <= 30000 
// -30000 <= obstacle[i][1] <= 30000 
// 答案保证小于 2 ^ 31 
// 
// Related Topics 贪心算法 
// 👍 101 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//        public:
//        struct PositionHash
//        {
//            size_t operator()(const pair<int, int> &val) const
//            {
//                return val.first ^ val.second;
//            }
//        };
//
//        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//            unordered_set<pair<int, int>, PositionHash> obs;
//            for (const auto &o : obstacles) {
//                obs.insert({o[0], o[1]});
//            }
//
//            int maxDestSq = 0;
//            int pos[2] = {0, 0};
//            int dir[2] = {0, 1};
//            for (int c : commands) {
//                if (c == -1) {
//                    dir[0] = -dir[0];
//                    swap(dir[0], dir[1]);
//                } else if (c == -2) {
//                    dir[1] = -dir[1];
//                    swap(dir[0], dir[1]);
//                } else if (c >= 1 && c <= 9) {
//                    while (c--) {
//                        int px = pos[0] + dir[0];
//                        int py = pos[1] + dir[1];
//                        if (obs.find({px, py}) != obs.end()) {
//                            break;
//                        }
//
//                        pos[0] = px;
//                        pos[1] = py;
//                    }
//
//                    int destSq = pos[0] * pos[0] + pos[1] * pos[1];
//                    if (destSq > maxDestSq) {
//                        maxDestSq = destSq;
//                    }
//                }
//
//            }
//
//            return maxDestSq;
//        }
//};


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<unsigned long long> hashObstacles;
        for (unsigned int i = 0; i < obstacles.size(); i++) {
            hashObstacles.insert((((unsigned long long)(unsigned int)obstacles[i][0]) << 32) + (unsigned int)obstacles[i][1]);
        }

        unsigned long long current = 0;
        int command, units, maxDistance = 0;
        int direction = 0, dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };
        for (unsigned int i = 0; i < commands.size(); i++) {
            command = commands[i];
            if (command == -1) {
                direction = (direction + 3) % 4;
                continue;
            }

            if (command == -2) {
                direction = (direction + 1) % 4;
                continue;
            }

            int x = (int)(current >> 32), y = (int)current;
            for (units = 1; units <= command; units++) {
                x += dx[direction];
                y += dy[direction];
                if (hashObstacles.find(((unsigned long long)(unsigned int)x << 32) + (unsigned int)y) != hashObstacles.end()) {
                    break;
                }
            }

            if (units != command + 1) {

                x -= dx[direction];
                y -= dy[direction];
            }

            int distance = x * x + y * y;
            maxDistance = (distance > maxDistance) ? distance : maxDistance;
            current = ((unsigned long long)(unsigned int)x << 32) + (unsigned int)y;
        }

        return maxDistance;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
