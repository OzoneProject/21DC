class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            //System.out.println(m);
            for (int p : piles) total += (p + m - 1) / m;
            //System.out.println(total);
            if (total > H) l = m + 1;
            else r = m;
        }
        return l;
    }
}