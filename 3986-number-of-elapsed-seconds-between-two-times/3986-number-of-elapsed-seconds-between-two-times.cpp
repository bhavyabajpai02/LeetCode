class Solution {
public:
    int time (string& s){
        int h = (s[0]-'a')*10+s[1]-'a';
        int m = (s[3]-'a')*10+s[4]-'a';
        int se = (s[6]-'a')*10+s[7]-'a';
        return h*3600+m*60+se;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = time(startTime);
        int end = time(endTime);
        return end - start;
    }
};