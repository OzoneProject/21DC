public boolean isValid(String s) {
    HashMap<Character, Character> map = new HashMap<Character, Character>();
    map.put('(', ')');
    map.put('[', ']');
    map.put('{', '}');
    Stack<Character> stack = new Stack<Character>();
    for(char ch : s.toCharArray()){
        if (map.keySet().contains(ch)) {
            stack.push(ch);
        } else if (map.values().contains(ch)) {
            if (!stack.empty() && map.get(stack.peek()) == ch)
                stack.pop();
            else
                return false;
        }
    }
    return stack.empty();
}