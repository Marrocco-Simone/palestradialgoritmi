void dfs(int node, const vector<vector<int>> &tree, vector<int> &subordinates) {
    for (int child : tree[node]) {
        dfs(child, tree, subordinates);
        subordinates[node] += subordinates[child] + 1;
    }
}

int coppie(int N, int *C) {
    vector<vector<int>> tree(N);
    int root = -1;

    for (int i = 0; i < N; i++) {
        if (C[i] == -1) {
            root = i;
        } else {
            tree[C[i]].push_back(i);
        }
    }
    vector<int> subordinates(N, 0);
    dfs(root, tree, subordinates);
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += subordinates[i];
    }
    return result;
}
