class Solution {
    public boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');   
    }
    
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> hs = new HashSet<>();
        Map<String, String> m1 = new HashMap<>();
        Map<String, String> m2 = new HashMap<>();
        for(String word : wordlist) {
            hs.add(word);
            m1.putIfAbsent(word.toLowerCase(), word);
            m2.putIfAbsent(devowel(word.toLowerCase()), word);
        }
        for(int i=0;i<queries.length;i++) {
            String queryL = queries[i].toLowerCase();
            String queryLV = devowel(queryL);
            if(hs.contains(queries[i])) {
                queries[i] = queries[i];
            } else if(m1.containsKey(queryL)) {
                queries[i] = m1.get(queryL);
            } else if(m2.containsKey(queryLV)) {
                queries[i] = m2.get(queryLV);
            } else {
                queries[i] = "";
            }
        }
        return queries;
    }
    public String devowel(String word) {
        StringBuilder ans = new StringBuilder();
        for (char c: word.toCharArray())
            ans.append(isVowel(c) ? '*' : c);
        return ans.toString();
    }
}