class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming = 0;
        while(x != 0 || y != 0){
            int a = x & 1;
            int b = y & 1;
            if(a != b)
                hamming = hamming + 1;
            x = x/2;
            y = y/2;
        }
        return hamming; 
    }
};