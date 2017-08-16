/*
    Example 1:
    Input: "x+5-3+x=6+x-2"
    Output: "x=2"
    Example 2:
    Input: "x=x"
    Output: "Infinite solutions"
    Example 3:
    Input: "2x=x"
    Output: "x=0"
    Example 4:
    Input: "2x+3x-6x=x+2"
    Output: "x=-1"
    Example 5:
    Input: "x=x+2"
    Output: "No solution"
*/
class Solution {
public:
    string solveEquation(string equation) {

        char c,flag='b';
        int a=0,b=0;        //ax+b
        int tempA=0,tempB=0,sign=1;  //flag 
        for(int i=0;i<equation.size();i++){
            c = equation[i];
            if(c=='+'||c=='-' ||c=='x' ||c=='='){
                //看看前面有没有
                if(tempA!=0){
                    if(flag) a+=tempA;
                    else a-=tempA;
                }
                if(tempB!=0){
                    if(flag) b+=tempB;
                    else b-=tempB;
                }

                if(c=='-') sign=0;
                flag='b';  tempA=0; temp=0;

                if(c=='='){
                    a = -a;
                    b = -b;
                }
            }

            if(c>='0' && c<='9'){
                //判断是a还是b
                for(int j=i+1;j<equation.size();j++){
                    //数字无视
                    //加减等于 则为B
                    if(equation[j]=='x'){
                        flag = 'a';
                        break;
                    }
                }
                if(sign=='a') tempA = tempA*10 + c-'0';
                else tempB = tempB*10 + c-'0';
            }
        }
        // ax+b = 0
        if(a==0 && b!=0) return "No solution";
        if(b==0) return "Infinite solutions";
        double x = (-b)/a;
        string ret = "x=";
        ret+=t.to_string();
        return ret;
    }
};

