stack<string> h_back, h_forward;
string cur;
BrowserHistory(string homepage) { cur = homepage; }
void visit(string url) {
    h_forward = stack<string>();
    h_back.push(cur);
    cur = url;
}
string back(int steps) {
    while (--steps >= 0 && !h_back.empty()) {
        h_forward.push(cur);
        cur = h_back.top();
        h_back.pop();
    }
    return cur;
}
string forward(int steps) {
    while (--steps >= 0 && !h_forward.empty()) {
        h_back.push(cur);
        cur = h_forward.top();
        h_forward.pop();
    }
    return cur;
}