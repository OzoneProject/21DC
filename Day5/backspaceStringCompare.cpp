class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '#'){ 
                if(!s.empty()) //if stack is empty and we pop, it will throw an exception, 
                    s.pop();   // so make sure stack is not empty.
            }
            else               //if S[i] is an alphabet
                s.push(S[i]);
        }
        
        for(int i = 0; i < T.length(); i++){
            if(T[i] == '#'){ 
                if(!t.empty()) 
                    t.pop();
            }
            else 
                t.push(T[i]);
        }
        
        if(s.size() != t.size()) //if size of stack are not same, the size of resulting
            return false;        //string will also not be same, therefore we return false
        
        while(!s.empty()){
            if(s.top() != t.top())  //checking the string in reverse order, if the alphabets
                return false;       // are same and in proper sequence
            s.pop(); 
            t.pop();
        }
                        //if all conditions are true, and there is no anomality in the two 
        return true;    // strings, we return true, i.e. strings are same.
    }                    
};