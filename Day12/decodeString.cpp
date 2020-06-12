class Solution {
public:
    string make(string& s, int& i){ // Here i and s are 'CALLED BY REFERENCE' ie. changing 
                                    // the value of i and s here will change the value of
                                    // i and s present in 'decodeString()'
        
        
        string res = "", k = ""; // 'res' will store the final result of this recursion/step 
                                 // and 'k' will store the string which was present in '[]'
                                 // to be repetitively stored n times in res.
        
        int n = 0; // No. of times k is present in res.
        
        while(isdigit(s[i]) == true){ // Extracting the entire value present before '[' ie 
                                      // opening of square brackets to get number of times
            n = n*10 + (s[i] - '0');  // k is to be repeated to store in res.
            i++;                      // Ex 24[abc] where n will be 24.      
        }
        
        for(i = i + 1; s[i] != ']'; i++){ //Iterating through string inside '[]' till ']'
                                          // is encountered.
            
            if(isdigit(s[i]))    // If char encountered is a digit, we call make() again, 
                k += make(s, i); // and add the returned string to k. That's why, this is
                                 // recursion i.e. function calling itself.
            
            else            // If char encountered is a character, add it to result as it
                k += s[i];  // is.
        }
        
        for(int j = 0; j < n; j++) // Adding k 'n' times to 'res'
            res += k;
        
        return res; // Returning the resultant string for this recursion/step.
    }
    
    string decodeString(string s) {
        
        string res = ""; // The result string, which will store the final result.
        
        for(int i = 0; i < s.length(); i++){ // Loop to iterate through the string
            
                                   // If a digit is present in the string, we know that the 
            if(isdigit(s[i]))      // digit and the numbers that follows it must be the 
                res += make(s, i); // number of times the string present inside '[]' must be
                                   // repeated. So we pass it to make() and it returns the
                                // result string formed after repeating the string inside.
            
            
            else                // If the character is an alphabet, simply add it to final
                res += s[i];    // resultant string.
        }
        
        return res; // Return the resultant string.
    }
};