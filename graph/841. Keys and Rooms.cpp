//
// Created by zhouhan on 2021/3/27.
//
#include "../common.h"
class Solution {
public:
    bool visited[1005];
    int cnt = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        fill(visited, visited + 1005, false);
        dfs(rooms, 0);
        return cnt == rooms.size();
    }

    void dfs(vector<vector<int>> &rooms, int i){
        if(rooms[i].empty()){
            return;
        }
        visited[i] = true;
        cnt ++;
        for(int j = 0; j < rooms[i].size(); j++){
            if(!visited[rooms[i][j]]){
                dfs(rooms, rooms[i][j]);
            }
        }
    }
};