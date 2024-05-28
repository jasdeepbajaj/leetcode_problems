class Solution {
public:
    int countDigits(int num) {
        int ans = 0; 
        int original = num;
        while(num>0){
            int rem = num%10;
            if (rem!=0 && original%rem == 0){
                ans++;
            }
            num = num/10;
        }
        return ans;
    }
};