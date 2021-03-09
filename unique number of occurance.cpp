class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i : arr) 
            um[i]+=1;
        for(auto a: um)
            cout<<a.first<<" "<<a.second<<endl;
            
        for(auto &a: um) {
              int ck=a.second;
              a.second=0;
            for(auto &a2: um) {
                //cout<<a2.second<<endl;
                if(a2.second == ck) return false;
            }
        }
        
        return true;
        
    }
};
