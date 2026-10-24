class Solution {
public:
    int helper( int monthday[] ,int mon ,int date ){
        int noOfDays = 0 ;
        for(int i=0 ; i<mon-1 ; i++){
           noOfDays += monthday[i];
        }
        return noOfDays+date ;
    }
    int split(string s , int start , int end){
        string curr = "";
        for(int i=start ; i<=end ; i++) curr+=s[i] ;
        int num = atoi(curr.c_str());
        return num ;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aamonth = split(arriveAlice , 0 , 1) ;
        int lamonth = split(leaveAlice , 0 , 1) ;
        int abmonth = split(arriveBob, 0 , 1) ;
        int lbmonth = split(leaveBob , 0 , 1) ;
        int aadate = split(arriveAlice , 3 , 4) ;
        int ladate = split(leaveAlice , 3 , 4) ;
        int abdate = split(arriveBob, 3 , 4) ;
        int lbdate = split(leaveBob , 3 , 4) ;
        int monthday[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
        int aaDays = helper(monthday, aamonth, aadate);
        int laDays = helper(monthday, lamonth, ladate);
        int abDays = helper(monthday, abmonth, abdate);
        int lbDays = helper(monthday, lbmonth, lbdate);
        int start = max(aaDays, abDays);
        int end = min(laDays, lbDays);
        if(start > end) return 0;
        return end-start+1 ;
    }
};