class Solution {
public:
    int getNumber(string& s){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(s.substr(0, 2));
        int date = stoi(s.substr(3, 2));

        for(int i = 0; i<month-1; i++){
            date += days[i];
        }
        return date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA = getNumber(arriveAlice);
        int leaveA = getNumber(leaveAlice);

        int arriveB = getNumber(arriveBob);
        int leaveB = getNumber(leaveBob);

        int left = max(arriveA, arriveB);
        int right = min(leaveA, leaveB);

        int ans = right - left + 1;

        return max(0, ans);
    }
};