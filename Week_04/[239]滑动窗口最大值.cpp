//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。 
//
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 进阶： 
//
// 你能在线性时间复杂度内解决此题吗？ 
//
// 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window 
// 👍 448 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int size) {
        if(num.empty()||size==0) return {};
        int l=0,r=0;//下一个要读取的数据
        int Max=INT32_MIN;

        for(;r<size&&r<num.size();++r){
            Max=max(Max,num[r]);
        }

        vector<int> res{Max};
        if(size>=num.size()) return res;
        while(r<num.size()){
            if(num[l]<Max){
                Max=max(Max,num[r]);
            }
            else{
                Max=INT32_MIN;
                for(int i=l+1;i<=r;++i)
                    Max=max(Max,num[i]);
            }
            res.push_back(Max);
            ++r;
            ++l;
        }
        return res;
    }
};


//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int> result;
//        if (k == 0) return result;
//        deque<int> w;
//        for (int i = 0, n = (int)nums.size(); i < n; i++) {
//            while (!w.empty() && w.front() <= i-k)
//                w.pop_front();
//            while (!w.empty() && nums[w.back()] <= nums[i])
//                w.pop_back();
//            w.push_back(i);
//            if (i >= k-1)
//                result.push_back(nums[w.front()]);
//        }
//        return result;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
