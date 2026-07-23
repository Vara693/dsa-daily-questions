// There is a biker going on a road trip. The road trip consists of n + 1 points at various altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int currGain = 0;
        int maxAltitude = 0;

        for (int i=1; i<=n; i++) {
            currGain = currGain + gain[i-1];

            maxAltitude = max(maxAltitude, currGain);
        }

        return maxAltitude;
    }
};