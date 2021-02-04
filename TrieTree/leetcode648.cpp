//
// Created by zhouhan on 2021/2/4.
//

#include "../common.h"

class Solution {
public:
    class Node{
    public:
        int end = 0;
        vector<Node *> nexts = vector<Node *>(26, nullptr);
    };
    Node *root = new Node();
    void add(string word){
        int n = word.size();
        int path = 0;
        Node *node = root;
        for(int i = 0; i < n; i++){
            path = word[i] - 'a';
            if(node->nexts[path] == nullptr){
                node->nexts[path] = new Node();
            }
            node = node->nexts[path];
        }
        node->end++;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        string ans;
        for(int i = 0; i < n; i++){
            add(dictionary[i]);
        }
        istringstream str(sentence);
        string tmp;
        while(str >> tmp){
            if(!ans.empty()) ans += " ";
            int m = tmp.size();
            Node *node = root;
            int path = 0;
            int i;
            for(i = 0; i < m; i++){
                path = tmp[i] - 'a';
                if(node->nexts[path] == nullptr){
                    ans += tmp;
                    break;
                }
                node = node->nexts[path];
                if(node->end != 0){
                    ans += tmp.substr(0,i + 1);
                    break;
                }
            }
            // 判断是否提前退出了前面的循环
            // 也就是遍历完了当前单词也没有找到词根
            // 就将自己加入到答案中
            if(i == m){
                ans += tmp;
            }
        }
        return ans;
    }
};

