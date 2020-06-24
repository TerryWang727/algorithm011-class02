//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp;
        temp=nums;
        int n=temp.size();
       sort(temp.begin(),temp.end());
       int i=0,j=n-1;
       while(i<j){
           if(temp[i]+temp[j]>target)j--;
          else if(temp[i]+temp[j]<target)i++;
          else break;
       }
       if(i<j){
      for(int k=0;k<n;k++){
          if(i<n&&nums[k]==temp[i]){
              ans.push_back(k);
              i=n;
          }
         else if(j<n&&nums[k]==temp[j]){
              ans.push_back(k);
              j=n;
          }
          if(i==n&&j==n)return ans;
      }
      }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
