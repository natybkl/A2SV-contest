class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxspace1=0;
        int maxspace2=0;
        int maxspace3=0;
        vector<int> v;
        int k=0;
        int j=seats.size();
        
        if(seats[0] == 0 ) {
            for(int i=0; i < seats.size(); i++) {
                if(seats[i] == 1) break;
                k++;
                maxspace1++;
            }
        }
        
        if(seats[seats.size()-1] == 0 ) {
            for(int i=seats.size()-1; i >= 0; i--) {
                if(seats[i] == 1) break;
                j--;
                maxspace2++;
            }
        }
        
        for(int i = k; i < seats.size() && i < j; i++) {
            if(seats[i] == 0) {
                for(int p=i; p < seats.size() && p < j; p++ ) {
                    if(seats[i] == 1) break;
                    maxspace3++;
                    i++;
                }
            }
               v.push_back(maxspace3);
               maxspace3=0;
        }
        
        
        int maxsp=max(maxspace1,maxspace2);
        int maxsp2=*max_element(v.begin(),v.end());
        
        if(maxsp2%2 == 0) maxsp2=maxsp2/2;
        else maxsp2=(maxsp2)/2 +1;
        
        return max(maxsp,maxsp2);
        
        
    }
};
