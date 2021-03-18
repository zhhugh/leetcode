#include "../common.h"
class Solution {
public:
    vector<string> preProcess(string s){
        int i = 0;
        vector<string> res;
        string t;
        while(i < s.size()){
            if(s[i] == ' '){
                i++;
            }else if(isdigit(s[i])){
                t += s[i++];
                if(i == s.size() || !isdigit(s[i])){
                    res.push_back(t);
                    t = "";
                }
            }else{
                string symbol;
                symbol += s[i++];
                res.push_back(symbol);
            }
        }
        return res;
    }
    string caculateStack(stack<string> &t){
        int ans = 0;
        bool add = true;
        while(!t.empty()){
            if(t.top().size() == 1 && !isdigit(t.top()[0])){
                add = (t.top() == "+" ) || !add;
            }else if(add){
                ans += stoi(t.top());
                add = true;
            }else{
                ans -= stoi(t.top());
                add = true;
            }
            t.pop();
        }
        return to_string(ans);
    }
    int calculate(string s) {
        auto nums = preProcess(s);
        stack<string> stk;
        for(string & str : nums){
            if(str == ")"){
                stack<string> t;
                while(stk.top() != "("){
                    t.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                stk.push(caculateStack(t));
            }else{
                stk.push(str);
            }
        }
        stack<string> t;
        while(!stk.empty()){
            t.push(stk.top());
            stk.pop();
        }
        return stoi(caculateStack(t));
    }
};