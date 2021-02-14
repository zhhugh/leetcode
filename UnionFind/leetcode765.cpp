//
// Created by zhouhan on 2021/2/14.
//
#include "../common.h"

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        parent = vector<int>(n / 2, 0);
        size = vector<int>(n / 2, 1);
        init(n / 2);
        for(int i = 0; i < n; i+=2){
            int x = row[i]/ 2;
            int y = row[i + 1] / 2;
            unionNode(x, y);
        }
        int ans = 0;
        for(int i = 0; i < n / 2; i++){
            if(parent[i] == i){
                ans += size[i] - 1;
            }
        }
        return ans;
    }

    void unionNode(int x, int y){
        int x_root = findRoot(x);
        int y_root = findRoot(y);
        if(x_root != y_root){
            if(size[x_root] > size[y_root]){
                parent[y_root] = x_root;
                size[x_root] += size[y_root];
            }else{
                parent[x_root] = y_root;
                size[y_root] += size[x_root];
            }
        }
    }

    int findRoot(int x){
        return x == parent[x] ? x : parent[x] = findRoot(parent[x]);
    }
    void init(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
};
