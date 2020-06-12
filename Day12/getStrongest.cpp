vector<int> getStrongest(vector<int>& arr, int k) {
    sort(begin(arr),end(arr));
    int m = arr[(arr.size()-1)/2];
    unordered_map<int,vector<int>> ratingNums;
    unordered_set<int> r;
    for (auto& a : arr){
        int rate = abs(a - m);
        ratingNums[rate].push_back(a);
        r.insert(rate);
    }
    vector<int> rs(r.begin(), r.end());
    sort(begin(rs),end(rs),greater<int>());
    vector<int> ans;
    for (int i = 0; i < rs.size(); i++){
        int rate = rs[i];
        sort(ratingNums[rate].begin(), ratingNums[rate].end(), greater<int>());
        for (int j = 0; j < ratingNums[rate].size() && ans.size() < k; j++){
            ans.push_back(ratingNums[rate][j]);
        }
    }
    return ans;
}