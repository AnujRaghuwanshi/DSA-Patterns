class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0, space = 0;
        for(const auto& ch : moves){
            if(ch == '_') space++;
            else if(ch == 'L') count--;
            else count++;
        }
        if(count == 0) return space;
        else if(count < 0) return abs(count-space);
        return count+space;
    }
};