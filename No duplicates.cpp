class Solution {
public:
   
    string remove(string &s, int k) {
        bool nomoredup=true;
        
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == s[i+1]) {
                int count = 1;
                for(int j = i; j < i+k && j < s.length()-1; j++ ) {
                    if(s[j] != s[j+1]) break;
                    count++;
                }
                
                if(count == k) {
                    s.erase(s.begin()+i,s.begin()+i+k);
                    nomoredup=false;
                }
            }
        }
        
        if(!nomoredup) remove(s,k);
        return s;    
    }
    
    string removeDuplicates(string s, int k) {
        return remove(s,k);
    } 
};
