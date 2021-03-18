//
// Created by zhouhan on 2021/2/26.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int val;
    Node *left, *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}

    Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};

Node * buildTree(vector<int> post, vector<int> in, int pLeft, int pRight, int inLeft, int inRight){
    if(pLeft > pRight){
        return nullptr;
    }
    Node *root = new Node(post[pRight]);
    int rInd = -1; // 根索引
    for(int i = inLeft; i <= inRight; i++){
        if(in[i] == post[pRight]){
            rInd = i;
            break;
        }
    }
    root->left = buildTree(post, in, pLeft, pLeft + rInd - inLeft - 1, inLeft, rInd - 1);
    root->right = buildTree(post, in, pLeft + rInd - inLeft, pRight - 1, rInd + 1, inRight);
    return root;
}

//int main(){
//    caculateStack<int> post;
//    caculateStack<int> in;
//    int n;
//    cin >> n;
//    for(int i = 0; i < n; i++){
//        int tmp;
//        cin >> tmp;
//        post.push_back(tmp);
//    }
//    for(int i = 0; i < n; i++){
//        int tmp;
//        cin >> tmp;
//        in.push_back(tmp);
//    }
//    Node *root = buildTree(post, in, 0, n - 1, 0, n - 1);
//    queue<Node *> que;
//    que.push(root);
//    caculateStack<int> ans;
//    while(!que.empty()){
//        Node *node = que.front();
//        que.pop();
//        ans.push_back(node->val);
//        if(node->left != nullptr){
//            que.push(node->left);
//        }
//        if(node->right != nullptr){
//            que.push(node->right);
//        }
//    }
//    for(int i = 0; i < n ; i++){
//        if(i != 0){
//            cout << " ";
//        }
//        cout << ans[i];
//    }
//    cout << endl;
//    return 0;
//}