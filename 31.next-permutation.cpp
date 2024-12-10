/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size() , i = len - 2;
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i >= 0) { //注意这个判断别忘了，用于处理最大数
            int j = len - 1;
            while (nums[j] <= nums[i]) {   //找出nums[i]后面大于nums[i]的最小数的下标
                j--;
            }
            swap(nums[i], nums[j]); //交换后，后面序列一定是升      
        }
        
        reverse(nums.begin()+i+1, nums.end()); //交换完后对nums[i]后面的数字进行从小到大排列
        
        
        return;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

