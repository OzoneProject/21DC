int numTimesAllBlue(vector<int>& light) {
    int maxx=0;int ans=0;int count=0;
    for(int i=0;i<light.size();i++)
    {
        maxx=max(maxx,light[i]);
        count++;
        if(count==maxx)ans++;
    }
    return ans;
}