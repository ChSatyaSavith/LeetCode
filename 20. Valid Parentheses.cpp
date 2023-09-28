class Solution {
public:
    bool isValid(string s) 
    {
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
                    if(code.empty())
                    {
                        return false;
                    }
                    char top = code.top();
                    if(top==s[i])
                    {
                        code.pop();
                    }
                    else
                    {
                        return false;
                    }
            }
        }
        if(!code.empty())
        {
            return false;
        }
        return true;
    }
};