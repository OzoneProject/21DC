class Solution {
    public String removeKdigits(String num, int k) {
        if(num == "0") return num;
        if(num.length() == k) return "0";
        
        StringBuilder sb = new StringBuilder(num);
        int i=0;
        int j=1;
        while(i < k && j < sb.length()){
            if(sb.charAt(j-1)>sb.charAt(j)){
                                // System.out.println("1"+"v "+sb.charAt(j-1));

                sb.deleteCharAt(j-1);
                i++;
                j--;
                if(j==0) j=1;
            }else
            {
                j++;
            }
        }
        j=sb.length()-1;
        while(i<k && j>=0){
            {              
                // System.out.println("2"+"v "+sb.charAt(j));

                sb.deleteCharAt(j--);
            i++;}
        }
        while(sb.charAt(0) == '0' && sb.length()>1)
        { 
            sb.deleteCharAt(0);               

        }
        return sb.toString();
    }
}
