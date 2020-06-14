int minReorder(int n, vector<vector<int>>& connections) {
    sort(connections.begin(), connections.end());
    set<int> path;
    path.insert(0);
    vector<vector<int>> left;
    int count = 0;
    for(auto const& i : connections){
        if(path.find(i[1]) != path.end())
            path.insert(i[0]);
        else if(path.find(i[0]) != path.end()){
            count++;
            path.insert(i[1]);
        }
        else
            left.push_back(i);
        
    }
    for(auto const& i : left) {
        if(path.find(i[1]) != path.end())
            path.insert(i[0]);
        else if(path.find(i[0]) != path.end()){
            count++;
            path.insert(i[1]);
        }
    }
    return count;
}