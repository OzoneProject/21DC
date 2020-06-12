public int[] getStrongest(int[] arr, int k) {
    int n = arr.length;
    Arrays.sort(arr);
    int med = arr[((n - 1) / 2)];
    TreeMap<Integer, List<Integer>> map = new TreeMap<>();
    for(int i=0;i<arr.length;i++) {
        int key = Math.abs(arr[i]-med);
        List<Integer> lst = map.getOrDefault(key, new ArrayList<>());
        lst.add(arr[i]);
        map.put(key, lst);
    }
    int[] ret = new int[k];
    int a = 0;
    while(a<k && !map.isEmpty()) {
        List<Integer> lst = map.get(map.lastKey());
        Collections.sort(lst);
        Collections.reverse(lst);
        int t = a;
        for(int i=0;i<Math.min(lst.size(),k-t);i++) {
            ret[a] = lst.get(i);
            a++;
        }
        map.remove(map.lastKey());
    }
    return ret;
}