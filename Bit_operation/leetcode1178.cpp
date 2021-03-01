//
// Created by zhouhan on 2021/2/26.
//
#include "../common.h"
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int>mp;
        // 生成Sw集合
        int wLen = words.size();
        for(int i = 0; i < wLen; i++){
            int k = 0; // 标记当前单词中字母的分布
            int len = words[i].size();
            for(int j = 0; j < len; j++){
                int path = words[i][j] - 'a';
                k |= (1 << path);
            }
            mp[k]++;
        }
        int pLen = puzzles.size();
        for(int i = 0; i < pLen; i++){
            int ans = 0;
            // 求puzzles[i]的子集
            int mask = 0;
            for(int j = 1; j < 7; j++){
                mask |= (1 << (puzzles[i][j] - 'a'));
            }
            int sub = mask;
            do{
                int s = sub | (1 << (puzzles[i][0] - 'a'));
                if(mp.find(s) != mp.end()){
                    ans += mp[s];
                }
                sub = (sub - 1) & mask;;
            }while(sub != mask);
            res.push_back(ans);
        }
        return res;
    }
};