// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int num : asteroids) {
            bool destroyed = false;
            while (!ans.empty() && ans.back() > 0 && num < 0) {
                if (abs(ans.back()) < abs(num)) {
                    ans.pop_back(); // previous asteroid destroyed
                    continue;       // keep checking with new top
                } else if (abs(ans.back()) == abs(num)) {
                    ans.pop_back(); // both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // current asteroid destroyed
                    break;
                }
            }
            if (!destroyed) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};