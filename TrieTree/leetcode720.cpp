//
// Created by zhouhan on 2021/2/3.
//

#include "../common.h"


//
// Created by zhouhan on 2021/2/3.
//




class Solution {
public:
    class Node{
    public:
        vector<Node *>nexts = vector<Node *> (26, nullptr);
    };

    static bool cmp(const string& s1, const string& s2){
        return s1.size() == s2.size()? s1 < s2 : s1.size() < s2.size();
    }
    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        int maxlen = 0;
        string maxstr = "";
        Node *root = new Node();
        for(int i = 0; i < n; i++){
            int len = words[i].size();
            Node *node = root;
            int path = 0;
            bool flag = false;
            for(int j = 0; j < len - 1; j++){
                path = words[i][j] - 'a';
                if(node->nexts[path] == nullptr){
                    flag = true;
                    break;
                }
                node = node->nexts[path];
            }
            if(flag){
                node->nexts[words[i][len - 1]] = new Node();
            }
            if(len > maxlen){
                maxlen = len;
                maxstr = words[i];
            }
        }
        return maxstr;
    }
};