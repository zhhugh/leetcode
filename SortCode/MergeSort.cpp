//
// Created by zhouhan on 2021/1/25.
//

// 归并排序
#include "../common.h"
void merge(vector<int> arr, int L, int R, int mid) {
    vector<int> help = vector<int>(R - L + 1, 0);
    int i = 0;
    int p1 = 0;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= R) {
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid) {
        help[i++] = arr[p1++];
    }
    while (p2 <= mid) {
        help[i++] = arr[p2++];
    }
    for (i = 0; i < help.size(); i++) {
        arr[L + i] = help[i];
    }
}

// 归并排序递归版本
void mergeSort(vector<int> &arr, int L, int R){
    if(L == R) return;
    int mid = L + ((R - L) >> 1);
    mergeSort(arr, L, mid);
    mergeSort(arr, mid + 1, R);
    merge(arr, L, R, mid);
}

// 归并排序非递归版本

void mergeSort2(vector<int> &arr){
    int N = arr.size();
    int mergeSize = 1;
    while(mergeSize < N){
        int L = 0;
        while(L < N){
            int M = L + mergeSize - 1;
            // 是否能凑出第一组
            if(M >= N){// 不能凑出第一组
                break;
            }
            //
            int R = min(M + mergeSize, N - 1);
            merge(arr, L, R, M);
        }
        if(mergeSize > N / 2){
            break;
        }
        mergeSize << 1;

    }
}