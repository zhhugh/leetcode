//
// Created by zhouhan on 2021/3/27.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node *>mp;
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node *cur = new Node(node->val);
        mp[node] = cur;
        vector<Node *> curNbs;
        vector<Node *> nbs = node->neighbors;
        for(auto & nb : nbs){
            if(mp.find(nb) != mp.end()){
                curNbs.push_back(mp[nb]);
            }else{
                curNbs.push_back(cloneGraph(nb));
            }
        }
        cur->neighbors = curNbs;
        return cur;
    }
};