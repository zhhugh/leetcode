//
// Created by zhouhan on 2021/3/16.
//
#include "../common.h"
class Solution {
public:
    struct cmp{
        bool operator()(vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        }
    };
    vector<int> networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> graph(n,vector<vector<int>>(n, vector<int>(2, 0)));
        for(auto time: times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, cmp>que;
        que.push({k, 0});
        vector<bool> visited(n, false);
        vector<int> minDis(n, INT_MAX);
        minDis[k] = 0;
        while(!que.empty()){
            auto cur = que.top();
            que.pop();
            visited[cur[0]] = true;
            for(auto nex: graph[cur[0]]){
                if(!visited[nex[0]] && (minDis[cur[0]] + nex[1] < minDis[nex[0]])){
                    minDis[nex[0]] = minDis[cur[0]] + nex[1];
                    que.push({nex[0], minDis[nex[0]]});
                }
            }
        }

        return minDis;
    }
};