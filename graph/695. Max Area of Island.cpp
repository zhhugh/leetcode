//
// Created by zhouhan on 2021/3/27.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int parent[90005];
    int size[90005];
    vector<int>dx{1, 0};
    vector<int>dy{0, 1};
    bool isIn(int x, int y, int m, int n){
        return x >= 0 && x < m && y >=0 && y < n;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        init(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = i * n + j;
                if(grid[i][j] == 1){
                    for(int k = 0; k < 2; k++){
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if(isIn(tx, ty, m, n) && grid[tx][ty] == 1){
                            int y = tx * n + ty;
                            union_root(x, y);
                        }
                    }
                }
            }
        }
        int maxVal = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1 && parent[i * n + j] == i * n + j){
                    maxVal = max(maxVal, size[i * n + j]);
                }
            }
        }
        return maxVal;
    }

    void init(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x){
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void union_root(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            parent[x_root] = y_root;
            size[y_root] += size[x_root];
        }
    }
};