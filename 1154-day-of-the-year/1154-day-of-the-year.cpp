class Solution {
public:
    bool isLeapYear(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        if (year % 4 == 0) return true;

        return false;
    }
    int getNumber(string& s){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(5, 2));
        int date = stoi(s.substr(8, 2));
        int year = stoi(s.substr(0,4));

        for(int i = 0; i<month -1; i++){
            date += days[i];
        }
        if(isLeapYear(year) && month >  2){
            return date + 1;
        }
        return date;
    }
    int dayOfYear(string date) {
        int ans = getNumber(date);
        return ans;
    }
};