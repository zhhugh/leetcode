#include "../common.h"
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        return dfs(s, 0, n - 1);
    }
    vector<vector<string>> dfs(string s, int l, int r){
        // 没数
        if(l > r){
            return {{}};
        }
        // 有数
        vector<vector<string>> ans;
        for(int i = r; i >= l; i--){
            // 先截取一个回文串， 再递归， 最少有一个答案
            string sub = s.substr(i, r - i + 1);
            vector<vector<string>> res;
            if(check(sub)){
                res = dfs(s, l, i - 1);
                for(auto &x: res){
                    x.push_back(sub);
                }
                ans.insert(ans.end(),res.begin(), res.end());
            }
        }

        return ans;
    }

    bool check(string s){
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> dp(n);
        for(int i = 0; i < n; i++){ // 枚举子结构
            vector<vector<string>> ans;
            //s[0...j...i],
            // s[j + 1...i]组成一个回文串， f[j] 是s[0...j]的所有可能性， 代表递归树中的孩子结点
            for(int j = 0; j <= i; j++){
                // [j..i]作为整体
                if(i == j && check(s.substr(0, j + 1))){
                    ans.push_back({s.substr(0, j + 1)});
                }else{
                    string sub = s.substr(j+1, i - j);
                    if(check(sub)){
                        for(auto x: dp[j]){
                            x.push_back(sub);
                            ans.push_back(x);
                        }
                    }
                }
            }
            dp[i] = ans;
        }
        return dp[n - 1];
    }

    bool check(string s){
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
};

class Solution3 {
public:
    vector<vector<string>> res;
    int len;
    bool f[20][20];
    vector<string> path;
    vector<vector<string>> partition(string s) {
        len = s.size();
        fill(f[0], f[20], true);
        for(int i = len - 1; i >= 0; i--){
            for(int j = i + 1; j < len; j++){
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int l){
        if(l == len){
            res.push_back(path);
            return;
        }
        for(int i = l; i <= len; i++){
            if(f[l][i]){
                path.push_back(s.substr(l, i - l + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

};

class Solution4 {
public:
    bool f[15][15];
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> dp(n, vector<vector<string>>{});
        fill(f[0], f[15], true);
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {// [0...i]
            for (int j = -1; j < i; j++) { //(j...i]
                if (j == -1 && f[j + 1][i]) {
                    dp[i].push_back({s.substr(0, i + 1)});
                }else if(f[j + 1][i]){
                    string sub = s.substr(j + 1, i - j);
                    for(auto x: dp[j]){
                        x.push_back(sub);
                        dp[i].push_back(x);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};