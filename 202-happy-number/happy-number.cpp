class Solution {
public:
    int square_of_digits(int num){

        int sum = 0;
        while (num!=0){
            int rem = num % 10;
            sum += rem*rem;
            num = num/10;
        }

        return sum;


    }
    bool isHappy(int num) {
        
        
        int ans = square_of_digits(num);
        
        unordered_set<int> seen;
        while (ans != 1){
            ans = square_of_digits(ans);
            
            if (seen.find(ans) != seen.end()) return false;
            
            seen.insert(ans);
        }
        
        

        if (ans == 1) return true;

        return false;
    }
};