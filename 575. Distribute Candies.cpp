/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> cand;
        for(int c:candies){
            cand.insert(c);
        }
        int count=cand.size();
        if(count>=candies.size()/2) return candies.size()/2;
        else return cand.size();
    }
};