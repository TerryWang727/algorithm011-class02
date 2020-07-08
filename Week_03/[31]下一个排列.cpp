//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须原地修改，只允许使用额外常数空间。 
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
//1,2,3 → 1,3,2 
//3,2,1 → 1,2,3 
//1,1,5 → 1,5,1 
// Related Topics 数组 
// 👍 557 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        if(nums.size() == 0||nums.size() == 1)
//            return;
//
//        for(vector<int>::reverse_iterator it = nums.rbegin();(it+1)!=nums.rend();it++)
//            if(*(it+1)<*it)  //找到第一个无序，将有序中的比该值大的最小值交换过来
//            {
//                //开始找该值
//                vector<int>::reverse_iterator it1 = nums.rbegin();
//                while((*it1)<=*(it+1))
//                    it1++;
//                int temp = *it1;
//                *it1 = *(it+1);
//                *(it+1) = temp;
//                //再向前做相反调整，即最小序列
//                sort(nums.rbegin(),it+1,greater<int>());  //注意sort的在闭右开区间
//                return;
//            }
//        sort(nums.begin(),nums.end());
//    }
//};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

void nextPermutation(vector<int>& nums) { // Example <1,0,3,2>
    // We need the next permutation to be <1,2,0,3>
    // Start from the right side and find the first element that is less than the one immediately after it.
    // That is 0.

    auto inversionPoint = is_sorted_until(rbegin(nums),rend(nums));
    if (inversionPoint == rend(nums)) { // Note that if no element is found that smaller than the one
        // immediately after it we have reached the end of the vector, meaning we are at the last valid permutation
        // In that case, we want to return the first permutation (simply sort the vector).
        reverse(rbegin(nums),rend(nums)); // Using reverse on a vector sorted in ascending order
        //(from right to left) will yield a vector that is sorted from left to right.
        return;
    }
    auto lowestUpper = upper_bound(rbegin(nums),inversionPoint, *inversionPoint); // Now we need to find the first number
    // that is higher than our inversion point of 0. That is 2.

    iter_swap(lowestUpper, inversionPoint); // We swap 0 and 2. We now have <1, 2, 3, 0>
    reverse(rbegin(nums), inversionPoint); // We reverse from 0 to 2 non inclusive of 2
    return; // We now arrive at  <1,2, 0, 3>
}

// If this was helpful please give me reputation. Thanks!


//leetcode submit region end(Prohibit modification and deletion)
