public List<String> buildArray(int[] target, int n) {
    List<String> l = new ArrayList<>();
    int j =0;
    if(target[target.length-1]<n)
        n = target[target.length-1];
    for(int i=1;i<n+1;i++){
        if(i == target[j]){
            l.add("Push");
            j++;
        }    
        else{
            l.add("Push");
            l.add("Pop");
        }
    }
    return l;
}