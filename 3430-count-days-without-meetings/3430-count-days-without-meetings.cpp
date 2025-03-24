class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        if (meetings.empty()) return days;
        
        std::sort(meetings.begin(), meetings.end());

        int occupiedDays = 0;
        int prevStart = meetings[0][0], prevEnd = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int currStart = meetings[i][0], currEnd = meetings[i][1];
            
            if (currStart <= prevEnd + 1) { 
                prevEnd = std::max(prevEnd, currEnd);
            } else { 
                occupiedDays += (prevEnd - prevStart + 1);
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }

        occupiedDays += (prevEnd - prevStart + 1);

        return days - occupiedDays;
    }
};
