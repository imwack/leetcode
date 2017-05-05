/*

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.

*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end(),[&](string str1,string str2){
            return (str1[0]<str2[0] || (str1[0]==str2[0]&&str1[1]<str2[1])|| (str1[0]==str2[0]&&str1[1]==str2[1]&&str1[3]<str2[3])|| (str1[0]==str2[0]&&str1[1]==str2[1]&&str1[3]==str2[3]&&str1[4]<str2[4]));
        })
        int min=60*24,t1,t2,diff;
        for(int i=0;i<timePoints.size()-1;i++){
            t2 = ((timePoints[i+1][0]-'0')*10+(timePoints[i+1][1]-'0'))*60 + (timePoints[i+1][3]-'0')*10+(timePoints[i+1][4]-'0');
            t1 = ((timePoints[i][0]-'0')*10+(timePoints[i][1]-'0'))*60 + (timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
            diff = t2-t1;
            if(diff<min) min=diff;
        }
        int i = timePoints.size()-1;
        t2 = ((timePoints[i][0]-'0')*10+(timePoints[i][1]-'0'))*60 + (timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
        t1 = ((timePoints[0][0]-'0')*10+(timePoints[0][1]-'0'))*60 + (timePoints[0][3]-'0')*10+(timePoints[0][4]-'0');
        diff = min(t2-t1,24*60-t2+t1);
        if(diff<min) min=diff;

        return diff;
    }
};