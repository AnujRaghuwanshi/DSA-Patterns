class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0,space = 0;
        for(const auto& ch : moves){
            if(ch == 'L') countL++;
            else if(ch == 'R') countR++;
            else space++;
        }
        if(countL == countR) return space;
        else if(countL > countR) return abs(countL-countR+space);
        return abs(countR-countL+space);
    }
};