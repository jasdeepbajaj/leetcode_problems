class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            int current = i;
            bool isSelfDividing = true;
            
            while(current > 0) {
                int rem = current % 10;
                if(rem == 0 || i % rem != 0) {
                    isSelfDividing = false;
                    break;
                }
                current = current / 10;
            }
            
            if(isSelfDividing) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};