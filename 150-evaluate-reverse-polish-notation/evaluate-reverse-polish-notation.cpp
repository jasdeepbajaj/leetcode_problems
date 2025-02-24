class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(auto strng : tokens){
            if(strng == "+"){
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a + b);
            }
            else if(strng == "-"){
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a - b);
            }
            else if(strng == "*"){
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a * b);
            }
            else if(strng == "/"){
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a / b);
            }
            else{
                stack.push(stoi(strng));
            }

        }    
        return stack.top();
    }
};