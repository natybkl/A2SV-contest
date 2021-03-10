class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        for(int j=0; j < pushed.size(); j++) {
                st.push(pushed[j]);
                cout<<st.top()<<" "<<endl;
                if(st.top() == popped[i]) {
                    while(st.top() == popped[i] && i < popped.size() && !st.empty()) {
                        cout<<st.top()<<" "<<endl;
                        st.pop();
                        i++;
                    }    
                }
        }
        
        
        return st.empty();
    }
};
