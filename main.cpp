#include <iostream>
#include "BinarySearch/leetcode530.cpp"



int main() {
    Solution2 s;
    vector<int> arr{3,3,7,7,10,11,11};
    int n = s.singleNonDuplicate(arr);
    cout << n << endl;
    return 0;
}
