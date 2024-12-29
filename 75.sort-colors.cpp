// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, cur = 0, blue = n - 1;
        while (cur <= blue) {
            if (nums[cur] == 0) {   //说明是红色的，放最前面
                swap(nums[cur], nums[red]);
                red++;
                cur++;   //>! 注意这里需要cur++; 这道题的关键
            }
            else if (nums[cur] == 2) {   //>! 蓝色放最后}
                swap(nums[cur], nums[blue]);
                blue--;
                //>! 注意这里不需要cur++; 这道题的关键
            }
            else {
                cur++;
            }
        }
    }
};

/**
 * 
 * 可以定义循环不变量: i左边的永远是0或者1，zero左边的永远是0，zero指向的位置一定不是0，two及右边的永远是2
为什么把0丢到前面去可以让i++，因为i前面的要么是0要么是1，不会把2换过来，那有没有可能把0换过来，不会，如果zero的位置是0，那么肯定在之前遍历的时候，i已经把这个0放到zero之内了
为什么遇到2不能让i++，因为在two满足约束之前时，two位置上的元素可能还是2，此时如果让i++，会违反i左边永远是0或者1的约束，所以i不能动
 * 
 */
 
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

