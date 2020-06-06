int sum;
public int rangeSumBST(TreeNode root, int L, int R) {
    sum = 0;
    dfs(root, L, R);
    return sum;
}
void dfs(TreeNode curr, int L, int R) {
    if(curr==null)
        return;
    if(curr.val>=L && curr.val<=R)
        sum+=curr.val;
    if(curr.val>L)
        dfs(curr.left, L, R);
    if(curr.val<R)
        dfs(curr.right, L, R);
}