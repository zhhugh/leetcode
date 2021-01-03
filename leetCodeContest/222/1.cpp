class Solution1 {
public:
    static bool cmp(vector<int>a, vector<int> b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        int len = boxTypes.size();
        for(int i = 0; i < len; i++){
            if(boxTypes[i][0] >= truckSize){
                ans += truckSize * boxTypes[i][1];
                break;
            }else{
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        return ans;
    }
};
