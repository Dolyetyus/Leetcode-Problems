vector<int> parent(26);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    };

    auto unite = [&](int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    };

    for (int i = 0; i < s1.size(); ++i)
        unite(s1[i] - 'a', s2[i] - 'a');

    string res;
    for (char c : baseStr)
        res += (char)(find(c - 'a') + 'a');

    return res;
