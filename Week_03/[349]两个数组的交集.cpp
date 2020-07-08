//给定两个数组，编写一个函数来计算它们的交集。 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
// 
//
// 示例 2： 
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4] 
//
// 
//
// 说明： 
//
// 
// 输出结果中的每个元素一定是唯一的。 
// 我们可以不考虑输出结果的顺序。 
// 
// Related Topics 排序 哈希表 双指针 二分查找 
// 👍 198 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> m(nums1.begin(), nums1.end());
//        vector<int> res;
//        for (auto a : nums2)
//            if (m.count(a)) {
//                res.push_back(a);
//                m.erase(a);
//            }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0;
        unordered_map<int,int> a;
        for(auto it=nums1.begin();it!=nums1.end();it++){
            a[*it]=1;
        }
        for(auto it=nums2.begin();it!=nums2.end();it++){
            auto it2=a.find(*it);
            if(it2!=a.end()){
                if(it2->second==1){
                    res.push_back(*it);
                    it2->second=2;}
            }
        }
        return res;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
