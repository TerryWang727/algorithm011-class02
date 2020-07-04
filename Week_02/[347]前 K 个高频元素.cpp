//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。 
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。 
// 你可以按任意顺序返回答案。 
// 
// Related Topics 堆 哈希表 
// 👍 382 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//最大堆 优先队列
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        int n=nums.size();
//        unordered_map<int,int> m;
//        for(int i=0;i<n;i++){
//            m[nums[i]]++;
//        }
//        priority_queue<pair<int,int>> pq;  //Fisrt element stores frequency and second element value
//        //As we have not use any compare function max heap will sort according to first element of pair
//        unordered_map<int,int>::iterator itr;
//        for(itr=m.begin();itr!=m.end();itr++){
//            pq.push(make_pair(itr->second,itr->first));
//        }
//        vector<int> ans(k);
//        for(int i=0;i<k;i++){
//            ans[i]=pq.top().second;
//            pq.pop();
//        }
//        return ans;
//    }
//};


//基于频率
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int  num : nums)
            ++m[num];
        /** as the word frequencies is at most nums.size() **/
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        /** we can fetch the top k largest element value from the array **/
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i)
        {
            for (int num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
