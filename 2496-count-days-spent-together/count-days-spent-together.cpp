#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrivalMonth = 10 * (arriveAlice[0] - '0') + (arriveAlice[1] - '0');
        int aliceLeaveMonth = 10 * (leaveAlice[0] - '0') + (leaveAlice[1] - '0');
        int bobArrivalMonth = 10 * (arriveBob[0] - '0') + (arriveBob[1] - '0');
        int bobLeaveMonth = 10 * (leaveBob[0] - '0') + (leaveBob[1] - '0');

        int aliceArrivalDate = 10 * (arriveAlice[3] - '0') + (arriveAlice[4] - '0');
        int aliceLeaveDate = 10 * (leaveAlice[3] - '0') + (leaveAlice[4] - '0');
        int bobArrivalDate= 10 * (arriveBob[3] - '0') + (arriveBob[4] - '0');
        int bobLeaveDate = 10 * (leaveBob[3] - '0') + (leaveBob[4] - '0');

        int maxArriveMonth = aliceArrivalMonth;
        int maxArriveDate = aliceArrivalDate;

        if(aliceArrivalMonth == bobArrivalMonth){
            maxArriveDate = max(aliceArrivalDate,bobArrivalDate);
        }
        else if(aliceArrivalMonth < bobArrivalMonth){
          maxArriveMonth = bobArrivalMonth;
          maxArriveDate = bobArrivalDate;
        }

        int minLeaveMonth = aliceLeaveMonth;
        int minLeaveDate = aliceLeaveDate;

        if(aliceLeaveMonth == bobLeaveMonth){
            minLeaveDate = min(aliceLeaveDate,bobLeaveDate);
        }
        else if(aliceLeaveMonth > bobLeaveMonth){
          minLeaveMonth = bobLeaveMonth;
          minLeaveDate = bobLeaveDate;
        }

        if(minLeaveMonth < maxArriveMonth){
          return 0;
        }

        vector<int> arr = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int days = 0;
        for(int i = maxArriveMonth + 1; i < minLeaveMonth;i++){
          days += arr[i];
        }

        int extraDays = maxArriveMonth == minLeaveMonth ? 
        minLeaveDate - maxArriveDate + 1: minLeaveDate + arr[maxArriveMonth] - maxArriveDate + 1;
        if(extraDays < 0){
          return 0;
        }

        return days + extraDays;
    }

};