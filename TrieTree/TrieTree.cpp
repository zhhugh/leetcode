////
//// Created by zhouhan on 2021/2/3.
////
#include "../common.h"


class Node{
public:
    int pass;
    int end;
    vector<Node *> nexts;

    Node(): pass(0), end(0), nexts(vector<Node *>(26, NULL)){
    };
};

class TrieTree{
public:
    Node * root;
    TrieTree() : root(new Node()){};
    void Insert(string word){
        if(word.empty()){
            return;
        }
        int len = word.size();
        int path = 0;
        Node *node = root;
        node->pass ++;
        for(int i = 0; i < len; i++){
            path = word[i] - 'a';
            if(node->nexts[path] == nullptr){
                node->nexts[path] = new Node();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end ++;
    }
    // 删除word
    void Delete(string word){
        if(!Search(word)) return;
        Node *node = root;
        node->pass--;
        int len = word.size();
        int path = 0;
        for(int i = 0; i < len; i++){
            path = word[i] - 'a';
            if(--node->nexts[path]->pass == 0){
                // 这里不能这么简单的处理,可能会造成内存溢出
                node->nexts[path] = nullptr;
                return;
            }
            node = node->nexts[path];
        }
        node->end--;
    }


    // 查找前缀树中有有几个word
    int Search(string word){
        Node *node = root;
        int path = 0;
        int len = word.size();
        for(int i = 0; i < len; i++){
            path = word[i] - 'a';
            if(node->nexts[path] == nullptr){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->end;
    }

    // 查找前缀出现的次数
    int PrefixNumber(string pre){
        if(pre.empty()){
            return 0;
        }
        int len = pre.size();
        Node *node = root;
        int path = 0;
        for(int i = 0; i < len; i++){
            path = pre[i] - 'a';
            if(node->nexts[path] == nullptr){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->pass;
    }

};