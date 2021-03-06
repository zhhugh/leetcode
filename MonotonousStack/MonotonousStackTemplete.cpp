//
// Created by zhouhan on 2021/3/6.
//
# include "../common.h"
class MonotonousStack{
public:
    vector<vector<int>> getNearLessNoRepeat(vector<int> arr){
        int n = arr.size();
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>(2, -1));
        stack<int> stk;
        for(int i = 0; i < n; i++){
            // 栈中的元素在【被动】更新答案，遇到了答案就弹出
            while(!stk.empty() && arr[i] < arr[stk.top()]){
                // 先弹出栈顶元素， 方便更新答案
                int j = stk.top();
                stk.pop();
                res[j][1] = i;
                res[j][0] = stk.empty() ?  -1 : stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int j = stk.top();
            stk.pop();
            res[j][0] = stk.empty() ? -1 : stk.top();
        }
        return res;
    }

    vector<vector<int>> getNearLess(vector<int> arr){
        int n = arr.size();
        stack<vector<int>> stk;
        vector<vector<int>> res = vector<vector<int>> (n, vector<int> (2, -1));
        for(int i = 0; i < n; i++){
            while(!stk.empty() && arr[i] < arr[stk.top()[0]]){
                vector<int> popIs = stk.top();
                stk.pop();
                for(auto popI : popIs){
                    res[popI][0] = stk.empty() ? -1 : stk.top().back();
                    res[popI][1] = i;
                }
            }
            if(!stk.empty() && arr[i] == stk.top()[0]){
                stk.top().push_back(i);
            }else{
                vector<int> pushLs{i};
                stk.push(pushLs);
            }
        }
        while(!stk.empty()){
            vector<int> popIs = stk.top();
            stk.pop();
            for(auto popI: popIs){
                res[popI][0] = stk.empty() ? -1 : stk.top().back();
            }
        }
        return res;
    }





};