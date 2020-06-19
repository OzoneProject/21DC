string longestDiverseString(int a, int b, int c) {
    int total = a+b+c;
    int A=0, B=0, C=0;
    string ret = "";
    while(total-->0) {
        if((a>=b && a>=c && A!=2) || (a>0 && (B==2|| C==2))){
            ret+="a";
            a--;
            A++;
            B=C=0;
        }
        else if((b>=a && b>=c && B!=2) || (b>0 && (A==2|| C==2))){
            ret+="b";
            b--;
            B++;
            A=C=0;
        }
        else if((c>=a && c>=b && C!=2) || (c>0 && (A==2|| B==2))){
            ret+="c";
            c--;
            C++;
            A=B=0;
        }
    }
    return ret;
}