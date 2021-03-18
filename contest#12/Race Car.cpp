class Solution {
public: 
    int racecar(int target) {

        vector<int> Node; 
        queue<vector<int>> q;
        int level,position,speed;
        q.push({0, 0, 1}); // level, position, Speed

        while(!q.empty()) {

            auto car = q.front();

            q.pop();

            level = car[0];

            position = car[1];
          
            speed = car[2];
          
            if(position == target) return level;
            
            if(position + speed < 10000 && position + speed > 0)

                q.push({level + 1, position + speed, speed*2});

            if(speed > 0 && position + speed > target) {

                q.push({level + 1, position, -1});

            } else if(speed < 0 && position + speed < target) {

                q.push({level + 1, position, 1});

            }

        }

        return 0;

    }

};

