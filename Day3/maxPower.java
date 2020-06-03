public int maxPower(String s) {
    int max = 0;
    Stack<Character> stk = new Stack<>();
    for(char ch : s.toCharArray()) {
        if(!stk.isEmpty() && stk.peek()!=ch) {
            max = Math.max(max, stk.size());
            while(!stk.isEmpty())
                stk.pop();
        }
        stk.push(ch);
    }
    max = Math.max(max, stk.size());
    return max;
}