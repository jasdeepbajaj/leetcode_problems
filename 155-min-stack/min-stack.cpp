class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
    }
    
    void push(int val) {
        int mini;
        if (st.empty()){
            mini = val;
            st.push({val, mini});
        }
        else{
            pair<int, int> last_pair = st.top();
            int last_min = last_pair.second;
            mini = min(val, last_min);
            st.push({val, mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */