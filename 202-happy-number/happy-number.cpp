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
        
        
        // int ans = square_of_digits(num);
        
        unordered_set<int> seen;
        while (num != 1){
            num = square_of_digits(num);
            
            if (seen.find(num) != seen.end()) return false;
            
            seen.insert(num);
        }
        
        

        return true;

    }
};