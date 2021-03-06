#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int N, L;
vector<int> user[1001];
int visited[1001];
int cnt;
void bfs(int node){
    queue<int> que;
    que.push(node);
    int level = 0;
    visited[node] = 1;
    while(!que.empty()){
        queue<int> nextQueue;
        if(level >= L){
            break;
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int & i : user[cur]){
                if(i != 0 && !visited[i]){
                    nextQueue.push(i);
                    cnt++;
                    visited[i] = 1;
                }
            }
        }
        level++;
        que = nextQueue;
    }
}
int main(){
    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            user[tmp].push_back(i);
        }
    }
    int n;
    cin >> n;
    while(n--){
        int node;
        cin >> node;
        fill(visited, visited + 1001, 0);
        cnt = 0;
        bfs(node);
        cout << cnt << endl;
    }
    return 0;
}