//
// Created by zhouhan on 2021/2/3.
//

#include "../common.h"


//
// Created by zhouhan on 2021/2/3.
//




class Solution {
public:
    // 字典树定义
    class Node{
    public:
        vector<Node *>nexts = vector<Node *> (26, nullptr);
    };
    // 比较器函数在类中一定要加static
    // 长度相等则比较字典序， 长度不等则长度小的在前面
    static bool cmp(const string& s1, const string& s2){
        return s1.size() == s2.size()? s1 < s2 : s1.size() < s2.size();
    }

    string longestWord(vector<string>& words) {
        int n = words.size();
        // 先将单词进行排序， 那么长度短的单词一定会排在前面，题目中说一次只能新增一个字母
        // 所以可以先看新加入的单词的前n - 1个字母组成的前缀是否被加入过，
        // 如果加入过，则这个新加入的单词可以在前面单词的基础上再加入最后一个字母形成
        // 那么这个单词就可以作为备选项
        // 将这个单词的最后一个字母加入到字典树中，在看该单词的长度是否能够更新最大值
        // 如果没有加入过， 则直接跳过这个单词
        sort(words.begin(), words.end(), cmp);
        int maxlen = 0;
        string maxstr = "";
        Node *root = new Node();
        for(int i = 0; i < n; i++){
            int len = words[i].size();
            Node *node = root;
            int path = 0;
            bool flag = false;
            // 检查前n - 1字符是否已经被加入过了
            for(int j = 0; j < len - 1; j++){
                path = words[i][j] - 'a';
                // 如果之前没有加入过， 则直接跳过这个单词
                if(node->nexts[path] == nullptr){
                    flag = true;
                    break;
                }
                node = node->nexts[path];
            }
            // 如果之前加入过前n - 1个字母， 则可以在加入最后一个字母
            if(flag){
                node->nexts[words[i][len - 1]] = new Node();
            }
            // 因为排序后，字典序小的单词在前面， 所以长度相等的时候不要更新， 大于的时候才更新
            if(len > maxlen){
                maxlen = len;
                maxstr = words[i];
            }
        }
        return maxstr;
    }
};