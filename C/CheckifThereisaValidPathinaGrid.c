int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int streetDirs[7][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {1,0,1,0},
    {0,0,1,1},
    {0,1,1,0},
    {1,0,0,1},
    {1,1,0,0}
};

bool canConnect(int fromDir, int toType) {
    int opposite = (fromDir+2) % 4;
    return streetDirs[toType][opposite];
}

bool dfs(int** grid, int m, int n, int i, int j, bool** visited) {
    if (i == m-1 && j == n-1) return true;

    visited[i][j] = true;
    int type = grid[i][j];

    for (int d = 0; d < 4; d++) {
        if (!streetDirs[type][d]) continue;

        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];

        if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

        if (visited[ni][nj]) continue;

        int nextType = grid[ni][nj];

        if (!canConnect(d, nextType)) continue;

        if (dfs(grid, m, n, ni, nj, visited)) return true;
    }

    return false;
}

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i<m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }

    return dfs(grid, m, n, 0, 0, visited);
}
