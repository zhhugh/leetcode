//
// Created by zhouhan on 2021/3/6.
//
#include "../common.h"
// 深度优先搜索
class Solution {
public:
    vector<vector<int>> G;
    vector<int> visited;
    vector<int> safe;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        G = graph;
        int n = G.size();
        visited.resize(n);
        safe.resize(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            fill(visited.begin(), visited.end(), 0);
            if(dfs(i)){
                ans.push_back(i);
                safe[i] = 1;
            }
        }
        return ans;
    }

    bool dfs(int node){
        if(visited[node]){
            return false;
        }
        if(safe[node]){
            return true;
        }
        visited[node] = 1;
        for(auto nex: G[node]){
            if(!dfs(nex)){
                return false;
            }else{
                safe[nex] = 1;
            }
        }
        visited[node] = 0;
        return true;
    }
};


// 拓扑排序
class Solution2 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<vector<int>> reGraph(n);
        vector<int> outSize(n, 0);
        queue<int> que;
        for(int i = 0; i < n; i++){
            outSize[i] = graph[i].size();
            if(outSize[i] == 0){
                que.push(i);
            }
            for(auto nex: graph[i]){
                reGraph[nex].push_back(i);
            }
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();
            ans.push_back(node);
            for(auto nex : reGraph[node]){
                outSize[nex]--;
                if(outSize[nex] == 0){
                    que.push(nex);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};