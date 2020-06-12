class Solution {
    int i = 0;
    public String decodeString(String s) {
        
        String res = "";
        
        for( ; i < s.length() && s.charAt(i) != ']'; i++){
            
            if(Character.isDigit(s.charAt(i)) == true){
                int n = 0;
                
                while(Character.isDigit(s.charAt(i)) == true){
                    n = n*10 + (s.charAt(i) - '0');
                    i++;
                }
                
                i += 1;
                
                String k = decodeString(s);
                
                for(int i = 0; i < n; i++)
                    res += k;
            }
            else
                res += s.charAt(i);
        }
        
        return res;
    }
}