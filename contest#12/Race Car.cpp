class Solution {
public: 
    int racecar(int target) {
        queue<vector<int>> q;
        int level,position,speed;
        q.push({0, 0, 1}); // level, position, Speed

        while(!q.empty()) {
            auto car = q.front();
            q.pop();

            level = car[0];
            speed = car[2];
            position = car[1];
         
            if(position == target) return level;
            
            // wondering if accelerating would get us to target
            if(position + speed <= 10000 && position + speed > 0)
                q.push({level + 1, position + speed, speed*2});
             
            // wondering if reversing would get us to target
            if(speed > 0 && position + speed > target) {
                q.push({level + 1, position, -1});

            } else if(speed < 0 && position + speed < target) {
                q.push({level + 1, position, 1});
            }
        }

        return -1;
    }

};

