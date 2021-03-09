class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int maxsub=0;
        int i=0,j=0;
        
        while(j<s.length()) {
            maxCost-=abs(s[j]-t[j]);
            if(maxCost<0) {
                maxCost+=abs(s[i]-t[i]);
                i++;
            }  
            maxsub=max(maxsub, j-i+1);
            j++;
              
        }

        return maxsub;   
    }
};
