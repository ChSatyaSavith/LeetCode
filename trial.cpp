#include <stack>
#include <iostream>
using namespace std;

int main()
{
    string s = "()[]{}";
    stack<char> code;
    for(int i = 0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(':
                    code.push(')'); //Adding antimatter so i can neutralize when there occurs matter
                    break;
                case '[':
                    code.push(']'); //Adding antimatter so i can neutralize when there occurs matter
                    break;
                case '{':
                    code.push('}'); //Adding antimatter so i can neutralize when there occurs matter
                    break;
                default:
                    char top = code.top();
                    cout<<top<<s[i]<<endl;
                    code.pop();
                    // if(top==s[i]) //Neutralizing open bracket with close bracket
                    // {
                    //     code.pop();
                    // }
                    // else
                    // {
                    //     return false;
                    // }
            }
        }
}