//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针 
// 👍 509 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    const int K = 4;
    int size;
    void search(const vector<int>& nums, int pos, int k, int target, vector<int>& v, vector<vector<int>>& vv)
    {
        if(k == 2)
        {
            int l = pos, r = size-1;
            while(l < r)
            {
                int t = nums[l]+nums[r];
                if(t > target) r--;
                else if(t < target) l++;
                else
                {
                    v.push_back(nums[l++]);
                    v.push_back(nums[r--]);
                    vv.push_back(v);
                    v.pop_back(), v.pop_back();
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
            }
        }
        else
        {
            for(int j = pos; j <= size-k; ++j)
            {
                int sum = 0;
                for(int i = j; i < k+j; ++i) sum += nums[i];
                if(sum > target) break;
                sum = nums[j];
                for(int i = 0; i < k-1; ++i) sum += nums[size-1-i];
                if(sum < target) continue;
                v.push_back(nums[j]);
                search(nums, j+1, k-1, target-nums[j], v, vv);
                v.pop_back();
                while(j<=size-k && nums[j+1]==nums[j]) j++;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<int> v;
        vector<vector<int>> vv;
        search(nums, 0, K, target, v, vv);
        return vv;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
