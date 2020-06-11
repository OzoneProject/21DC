class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_set<char> set; // Equivalent to HashSet in Java. Used to store values in
                                 // a Hash table.
        
        int len = 0; // length of the resulting palindrome
        
        for(char i : s){    //A for-each loop where i will take the value of each character
                            // in the string s.
            
            if(set.find(i) == set.end()) //if element is not present in the set, insert the 
                set.insert(i);           // element in the set.
            
            else{               //If element is already present in the set, we know that this
                len += 2;       // is the second time this element is present in s, so it will
                set.erase(i);   // contribute to the resulting palindrome. Length of the
            }                   // palindrome is increased by 2, and the element is removed.
        }
        
        if(set.empty() == false) // As we get an EVEN length of palindrome, we can still add a
            len += 1;            // character in the centre and it will still be a palindrome.
                                 // So, if HashSet is not empty, that means it has a single 
                                 // char left, which can contribute to length of palindrome.
        
        return len; //Return the length of resulting palindrome.
    }
};