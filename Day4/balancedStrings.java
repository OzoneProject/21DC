class Solution {
   public int balancedStringSplit(String s) {
    int bal = 0, res = 0;
    for (int i = 0; i < s.length(); i++) {
        bal += s.charAt(i) == 'L' ? 1 : -1;
        if (bal == 0) res++;
    }
    return res;
}
}