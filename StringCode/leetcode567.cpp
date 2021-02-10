//
// Created by zhouhan on 2021/2/10.
//

#include "../common.h"
//

class Solution {
public:
    int l = 0, r = 0;
    int visited[26];
    bool checkInclusion(string s1, string s2) {
        // 统计每个字符出现的次数
        for(auto c: s1){
            visited[c - 'a']++;
        }
        int len1 = s1.size();
        int len = s2.size();
        // [l...r) 匹配成功
        for(int i = 0; i < len; i++){
            int path = s2[i] - 'a';
            // 如果还缺少当前的字符
            if(visited[path] > 0){
                r++;
                visited[path]--;
            }else{
                while( visited[path] == 0 && l < r){
                    visited[s2[l++] - 'a']++;
                }
                // 被前面的字符占用了
                if(visited[path] > 0){
                    r++;
                    visited[path]--;
                }else{ // s1中没有出现过这个字符
                    l = i + 1;
                    r = l;
                    if(l >= len1){
                        return false;
                    }
                }
            }
            if(r - l == len1){
                return true;
            }
        }
        return false;
    }
};
