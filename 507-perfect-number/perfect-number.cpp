class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1) return false;
        for (int i = 1; i<=sqrt(num); i++){
            if(num%i == 0){
                sum+=i;
                if (i != num/i && num/i != num){
                    sum += num/i;
                }
            }
        }
        cout<<sum;
        if (sum == num) return true;
        else return false;
    }
};