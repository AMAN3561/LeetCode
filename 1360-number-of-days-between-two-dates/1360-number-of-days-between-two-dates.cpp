class Solution {
public:
    bool isLeapYear(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        if (year % 4 == 0) return true;

        return false;
    }
    int getNumber(string& s) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int date = stoi(s.substr(8, 2));
        int month = stoi(s.substr(5, 2));
        int year = stoi(s.substr(0, 4));

        

        for(int i = 0; i<month - 1; i++){
            date += days[i];
        }
        for (int y = 1971; y < year; y++) {
            if (isLeapYear(y)) {
                date += 366;
            } else {
                date += 365;
            }
        }
        if(isLeapYear(year) && month > 2){
            return date + 1;
        }
        return date;
    }
    int daysBetweenDates(string date1, string date2) {
        int date_1 = getNumber(date1);
        int date_2 = getNumber(date2);

        int ans = abs(date_2 - date_1);
        return ans;
    }
};