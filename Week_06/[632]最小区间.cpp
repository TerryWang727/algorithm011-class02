//你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。 
//
// 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。 
//
// 示例 1: 
//
// 
//输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
//输出: [20,24]
//解释: 
//列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
//列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
//列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
// 
//
// 注意: 
//
// 
// 给定的列表可能包含重复元素，所以在这里升序表示 >= 。 
// 1 <= k <= 3500 
// -105 <= 元素的值 <= 105 
// 对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。 
// 
// Related Topics 哈希表 双指针 字符串 
// 👍 128 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
struct NUM{
    int val;
    int pos;
};
struct INTERVAL_RST{
    int start;
    int end;
};
bool comparenum(NUM &num1,NUM &num2){
    if(num1.val<num2.val){
        return true;
    }
    return false;
}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int size = nums.size();
        vector<NUM> allNum;
        NUM tmp = { 0 };
        for (int i = 0; i < size; i++) {
            int size_interv = nums[i].size();
            for (int j = 0; j < size_interv; j++) {
                tmp.val = nums[i][j];
                tmp.pos = i;
                allNum.push_back(tmp);
            }
        }
        sort(allNum.begin(), allNum.end(), comparenum);
        int numsize = allNum.size();
        vector<int> IntervalFlag(size, 0);
        int left = 0;
        int right = 0;
        int calculate = 0;
        int mindif = allNum[numsize - 1].val - allNum[0].val;
        int start = allNum[0].val;
        int end = allNum[numsize - 1].val;
        int starttmp = 0;
        int endtmp = 0;
        for (int i = 0; i < numsize; i++) {
            int pos = allNum[i].pos;
            if (IntervalFlag[pos] == 0) {
                IntervalFlag[pos] = 1;
                calculate++;
            } else {
                IntervalFlag[pos]++;
            }

            while (calculate == size) {
                starttmp = allNum[left].val;
                endtmp = allNum[i].val;
                int dif = endtmp - starttmp;
                if (dif < mindif) {
                    start = starttmp;
                    end = endtmp;
                    mindif = dif;
                } else if (dif == mindif) {
                    if (starttmp < start) {
                        start = starttmp;
                        end = endtmp;
                    }
                }
                //收缩左边
                int pos2 = allNum[left].pos;
                if (IntervalFlag[pos2] == 1) {
                    calculate--;
                }
                IntervalFlag[pos2]--;
                left++;
            }
        }

        vector<int> Rst = { start, end };
        return Rst;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
