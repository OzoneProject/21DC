public int numMatchingSubseq(String S, String[] words) {
    int cnt = 0;
    HashSet<String> sub=new HashSet<>();
    for(String word : words) {
        boolean toAdd = true;
        if(sub.contains(word)){
            cnt++;
            continue;
        }
        int index=-1;
        for(char ch : word.toCharArray()){
            index=S.indexOf(ch,index+1);
            if(index==-1) {
                toAdd = false;
                break;
            }
        }
        if(toAdd) {
            sub.add(word);
            cnt++;
        }
    }
    return cnt;
}