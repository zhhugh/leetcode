#include "common.h"
using namespace std;


//下文大量用到pair<int,int>，所以给他一个缩写
#define PII pair<int,int>
int N,M;
//adj[i]中保存邻边，pair.first为邻居编号，pair.second为之间的距离
vector<PII>adj[201];
bool visited[201]={0};
int dis_sum=0;

//利用堆优化的Dijkstra算法，寻找最近的未访问过的点
int findNear(int start){
    int mindis[201];
    memset(mindis,0x3f,sizeof(mindis));
    mindis[start]=0;
    //优先队列中的pair.first为路程，pair.second为当前点编号。pair较小的优先
    priority_queue<PII,vector<PII>,greater<PII>>Q;
    Q.emplace(0,start);
    while(Q.size()){
        auto [curdis,cur]=Q.top();
        Q.pop();
        if(curdis!=mindis[cur])continue;
        // 没有被访问， 直接走
        if(!visited[cur]){
            dis_sum+=curdis;
            return cur;
        }
        // 当前结点是被访问过的
        for(auto [neighbor,dis]:adj[cur]){
            if(mindis[neighbor]>curdis+dis){
                mindis[neighbor]=curdis+dis;
                Q.emplace(mindis[neighbor],neighbor);
            }
        }
    }
    return -1;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int s1,s2,dist;
        cin>>s1>>s2>>dist;
        adj[s1].emplace_back(s2,dist);
        adj[s2].emplace_back(s1,dist);
    }
    vector<int>path;
    int cur=0;
    do{
        visited[cur]=true;
        path.push_back(cur);
        cur=findNear(cur);
    }while(cur>=0);
    //进行输出
    for(int i=0;i<path.size();i++){
        if(i)cout<<' ';
        cout<<path[i];
    }
    cout<<'\n';
    if(path.size()<N+1){
        vector<int>lose;
        for(int i=0;i<=N;i++){
            if(!visited[i])lose.push_back(i);
        }
        for(int i=0;i<lose.size();i++){
            if(i)cout<<' ';
            cout<<lose[i];
        }
    }
    else{
        cout<<dis_sum;
    }
}