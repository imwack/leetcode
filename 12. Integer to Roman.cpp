class Solution {
public:
    string intToRoman(int num) {
        // I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
        string roman ;
        string dic[4][10]=
        {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},    //0-9
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},    //10-90
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},    //100-900
            {"","M","MM","MMM"}
        };
        roman+=dic[3][num/1000%10];
        roman+=dic[2][num/100%10];
        roman+=dic[1][num/10%10];
        roman+=dic[0][num%10];
        return roman;
    }
};