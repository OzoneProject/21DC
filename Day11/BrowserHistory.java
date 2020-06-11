class BrowserHistory {
    public:
        stack<string> f;
        stack<string> b;
        BrowserHistory(string homepage) {
            f.push(homepage);
        }
        
        void visit(string url) {
            f.push(url);
            b.clear();
        }
        
        string back(int steps) {
            while(f.size() > 1 && steps-->0) {
                b.push(f.pop());
            }
            return f.peek();
        }
        
        string forward(int steps) {
            while(!b.isEmpty() && steps-->0) {
                f.push(b.pop());
            }
            return f.peek();
        }
    };
    
    /**
     * Your BrowserHistory object will be instantiated and called as such:
     * BrowserHistory* obj = new BrowserHistory(homepage);
     * obj->visit(url);
     * string param_2 = obj->back(steps);
     * string param_3 = obj->forward(steps);
     */