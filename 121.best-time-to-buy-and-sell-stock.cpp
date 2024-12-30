/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);

        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

