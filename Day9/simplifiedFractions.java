public List<String> simplifiedFractions(int n) {
    List<String> lst = new ArrayList<>();
    if(n<2)
        return lst;
    int num = 1, den = 2;
    while(num<n) {
        while(den<=n) {
            if(gcd(num, den)==1 && num<den)
                lst.add(num+"/"+den);
            den++;
        }
        den = 2;
        num++;
    }
    return lst;
}
int gcd(int a, int b) {
    if(a!=0 && b!=0) {
        if(a>b)
        return gcd(a%b, b);
        else
        return gcd(a, b%a);
    }
    return Math.max(a,b);
}