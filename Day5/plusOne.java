class Solution {
    public int[] plusOne(int[] a) {

        int length=a.length-1;
        while(length>=0)
        
        {
            a[length]=a[length]+1;
            int carry=a[length]/10;
            if(carry==1)
            {
                a[length]=0;
                length=length-1;
            }
            else break;
        }
        if(a[0]==0)
        {
            int[] array=new int[a.length+1];
            array[0]=1;
            return array;
        }
        return a;
}
}

