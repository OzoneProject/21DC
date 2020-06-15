public List<String> wordSubsets(String[] A, String[] B) {
    int[] union = new int[26];
    for (String b : B) {
        int[] count = countWords(b);
        for (int i = 0; i < 26; i++) {
            union[i] = Math.max(union[i], count[i]);
        }
    }
    
    List<String> res = new ArrayList<>();
    for (String a : A) {
        int[] count = countWords(a);
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (union[i] <= count[i]) c++;
        }
        if (c == 26) res.add(a);
    }
    
    return res;
}

private int[] countWords(String str) {
    int[] count = new int[26];
    for (char c : str.toCharArray()) {
        count[c - 'a']++;
    }
    return count;
}