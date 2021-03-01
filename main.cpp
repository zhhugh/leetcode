#include "Bit_operation/leetcode1178.cpp"

int main(){
    Solution s;
    vector<string> w{"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> p{"gaswxyz"};
    vector<int> ans = s.findNumOfValidWords(w, p);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}