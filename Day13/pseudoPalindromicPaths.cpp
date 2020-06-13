int cnt[10] = {};
int pseudoPalindromicPaths(TreeNode* n, int odds = 0, int res = 0) {
    if (n != nullptr) {
        odds += ++cnt[n->val] % 2 ? 1 : -1;
        if (n->left == n->right)
            res = odds < 2 ? 1 : 0;
        else
            res = pseudoPalindromicPaths(n->left, odds) 
                + pseudoPalindromicPaths(n->right, odds);
        odds += --cnt[n->val] % 2 ? -1 : 1;
    }
    return res;
}