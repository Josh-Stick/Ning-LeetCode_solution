/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) {
        stack<int> st;
        int res = 0;
        for (int i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    st.pop();
                    if (st.empty()) res = max(res, i - start + 1);
                    else res = max(res, i - st.top()); //
                }
                else start = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

