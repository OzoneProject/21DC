class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end()); //Sorting both the vectors using
                                                            // the in-built sort function.
        sort(verticalCuts.begin(), verticalCuts.end()); // Sorting is done in order to 
                                                        // arrange the horizontal cuts in 
                           // the order from top to bottom, and vertical from left to right. 
                           // This is done to get the difference i.e. the length and breadth 
                           // of the rectangle piece which results from cutting the cake.
        
        int maxH = 0, maxV = 0; //These will store the maximum height(length) and 
                                // width(breadth) of the piece.
        
        int m = horizontalCuts.size(), n = verticalCuts.size();
        
        maxH = max(maxH, horizontalCuts[0]); // Getting maximum of current maxH and length 
                                             // of piece from top to first cut.
        
        for(int i = 1; i < m; i++){ //Iterating through horizontal cuts.
            
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
                    // Comparing and storing max of maxH and the distance(height) between 
                    // the previous and current cut.
        }
        
        maxH = max(maxH, h - horizontalCuts[m - 1]); // Getting maximum of maxH and length 
                                             // of piece from last cut to bottom of cake.
        
        maxV = max(maxV, verticalCuts[0]); // Getting maximum of current maxV and breadth 
                                           // of piece from left(start) to first cut.
        
        for(int i = 1; i < n; i++){     //Iterating through vertical cuts.
        
            maxV = max(maxV, verticalCuts[i] - verticalCuts[i-1]);
                    // Comparing and storing max of maxV and the distance(breadth) between 
                    // the previous and current cut.
        }
        
        maxV = max(maxV, w - verticalCuts[n - 1]);  // Getting maximum of maxV and length 
                                             // of piece from last cut to right of cake.
        
                                                    // Returning area modulo 10^9 + 7
        return (long)maxH * maxV % 1000000007;    // Using long as such a big number 
                                                    // cannot be stored in int.
    }
};