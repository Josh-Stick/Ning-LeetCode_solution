/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
    //dp解法
    //   vector<vector<int>> dp(s.size(), vector<int>(s.size(), false));
    //     int begin = 0, maxLen = 1;
    //     for (int i = s.size() - 1; i >= 0; i--) {
    //         for (int j = i; j < s.size(); j++) {
    //             if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
    //                 dp[i][j] = true;
    //                 if (j - i + 1 >= maxLen) {
    //                     begin = i;
    //                     maxLen = j - i + 1;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(begin, maxLen);
    //中心拓展
    if(s.length() < 1) return "";
    int start = 0, end = 0;
    for(int i = 0; i < s.length(); i++) {
        int len1 = extend(s, i, i); //奇数
        int len2 = extend(s, i, i+1); //偶数
        int len = max(len1, len2);
        if(len > end - start) {
            start = i -(len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
    }  
    int extend(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left --;
            right ++;
        }
        return right - left -1; //right - left + 1 - 2
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

