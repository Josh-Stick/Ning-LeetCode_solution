/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    vector<string>ans;
    int len;
    void dfs (string s, int a, int b) {
        if (a < b || a > len || b > len) return;
        if (a == len && b == len) {//找到解
            ans.push_back(s);
            //cout<<s<<endl;
            return;
        }
        s += '(';
        dfs ( s, a+1, b);
        s.pop_back();

        s += ')';
        dfs (s, a, b+1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        len = n;
        string s;
        s += '(';
        dfs (s,1,0);//字符串s 左括号数1 右括号数
        return ans;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

