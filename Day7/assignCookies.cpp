class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end()); // Inbuilt sort function, which takes in the range, you want
                                  // to sort, in form of iterators. Here, g.begin() is the 
                                  // beginning iterator g.end() is ending.
        
        sort(s.begin(), s.end()); // Sorting both the arrays/vectors in increasing order
        
        int i = 0; // Pointer(or index) pointing to the current element which satisifes the 
                   // condition in the question.
        
        for(int j = 0; j < s.size(); j++){ //Iterating through both, size and the greed array.
            
            if(i == g.size()) //If we reach end of greed array, that means every child has
                break;        // been given a cookie. So, we break the loop.
            
            if(s[j] >= g[i]) //If the size of cookie is NOT less than greed, then, that child
                i++;         // is given that cookie, and we move on to the next child.
        }
                    //Return the index of greed upto which, cookies have been provided. That
        return i;   // will give the no. of children who got the cookies.
    }
};