//
// Created by zhouhan on 2021/3/5.
//
#include "../common.h"
class Solution {
public:
    vector<vector<bool>> dp;
    bool divisorGame(int N) {
        dp = vector<vector<bool>>(2, vector<bool>(N + 1, false));
        return f(N);
    }

    bool f(int N){
        // 如果有数可拿
        for(int i = 1; i < N; i++){
            if(N % i == 0){
                if(g(N - i)){
                    return true;
                }
            }
        }
        // 如果无数可拿
        return false;
    }

    bool g(int N){
        // 如果有数可拿
        for(int i = 1; i < N; i++){
            if(N % i == 0){
                if(!f(N - i)){
                    return false;
                }
            }
        }
        // 如果无数可拿
        return true;
    }
};


class Solution2 {
public:
    vector<vector<bool>> dp;
    bool divisorGame(int N) {
        dp = vector<vector<bool>> (2, vector<bool>(N + 1, false));
        dp[0][1] = false;
        dp[1][1] = true;
        for(int i = 2; i <= N; i++){
            // 先手
            for(int j = 1; j < i; j++){
                if(i % j == 0){
                    // 如果有一次机会能赢就是赢
                    if(dp[1][i - j]){
                        dp[0][i] = true;
                        break;
                    }
                }
            }
            // 后手
            for(int j = 1; j < i; j++){
                dp[1][i] = true;
                if(i % j == 0){
                    // 如果有一次机会输， 那么就是输
                    if(!dp[0][i - j]){
                        dp[1][i] = false;
                        break;
                    }
                }
            }
        }
        return dp[0][N];
    }
};

class Solution3 {
public:
    bool divisorGame(int N) {
        return (N & 1) == 0;
    }
};