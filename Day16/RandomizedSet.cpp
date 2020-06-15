class RandomizedSet {
    unordered_map<int, list<int>::iterator> s;
    list<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) == s.end()){
            v.push_front(val);
            s[val] = v.begin();
            return true;
            }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end()){
            v.erase(s[val]);
            s.erase(val);
            return true;
            }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int x = rand() % v.size();
        list<int> :: iterator it = v.begin();
        advance(it, x);
        return *it;
    }
};