public int minReorder(int n, int[][] connections) {
    Arrays.sort(connections, (a,b) -> a[1]-b[1]);
    Set<Integer> path = new HashSet<>();
    path.add(0);
    List<int[]> left = new ArrayList<>();
    int cnt = 0;
    for(int[] i : connections) {
        if(path.contains(i[1]))
            path.add(i[0]);
        else if(path.contains(i[0])){
            cnt++;
            path.add(i[1]);
        } else {
            left.add(i);
        }
    }
    for(int[] i : left) {
        if(path.contains(i[1]))
            path.add(i[0]);
        else if(path.contains(i[0])){
            cnt++;
            path.add(i[1]);
        }
    }
    return cnt;
}