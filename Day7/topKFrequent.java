class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> hm=new HashMap();
        for(int i=0;i<words.length;i++) {
            if(hm.containsKey(words[i])) {
                int x=(int)hm.get(words[i]);
                x++;
                hm.put(words[i],x);
            }
            else 
                hm.put(words[i],1);
        }
        List<String> candidates = new ArrayList(hm.keySet());
        Collections.sort(candidates, (w1, w2) -> hm.get(w1).equals(hm.get(w2)) ?
                w1.compareTo(w2) : hm.get(w2) - hm.get(w1));
        List<String> l=new ArrayList<>();
        for(int i=0;i<k;i++)
            l.add(candidates.get(i));
        return l;
    } 
}