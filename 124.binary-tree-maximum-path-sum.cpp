/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=
 *
 * [124] 二叉树中的最大路径和
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;   // 递归终止条件
        int left_max = max(dfs(root->left), 0);   // 左子树最大路径和
        int right_max = max(dfs(root->right), 0);  // 右子树最大路径和
        max_sum = max(max_sum, left_max + right_max + root->val);  // 更新最大路径和
        return max(left_max, right_max) + root->val;   ///向root的父结点返回经过root的单边分支的最大路径和
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

