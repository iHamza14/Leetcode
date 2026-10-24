class Solution {
public:

    int calcDay(string& day, const vector<int>& pref) 
    {
        int month = stoi(day.substr(0,2));
        int date = stoi(day.substr(3));
        return pref[month-1] + date;
    }
    int countDaysTogether(string aa, string la, string ab, string lb) 
    {
        vector<int> m = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
        vector<int> pref(13,0);
        for(int i =0; i<12; i++)
        {
            pref[i+1] = pref[i] + m[i];
        }

        int aaDay = calcDay(aa,pref);
        int laDay = calcDay(la,pref);
        int abDay = calcDay(ab,pref);
        int lbDay = calcDay(lb,pref);

        return max(0, min(lbDay,laDay) - max(aaDay,abDay) +1);


        
    }
};