class Solution {
    public int longestPalindrome(String s) {
        
        Set<Character> set = new HashSet<>();
        int len = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(set.contains(s.charAt(i)) == false)
                set.add(s.charAt(i));
            
            else {
                len += 2;
                set.remove(s.charAt(i));
            }
        }
        
        if(set.isEmpty() == false)
            len += 1;
        
        return len;
    }
}