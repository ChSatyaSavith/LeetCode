class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;

        for(auto operand: tokens)
        {
                if(operand=="+")
                {
                    int y = s.top();
                    s.pop();
                    int x = s.top();
                    s.pop();
                    int z = x+y;
                    s.push(z);
                }
                else if(operand=="-")
                {
                    int y = s.top();
                    s.pop();
                    int x = s.top();
                    s.pop();
                    int z = x-y;
                    s.push(z);
                }
                else if(operand=="/")
                {
                    int y = s.top();
                    s.pop();
                    int x = s.top();
                    s.pop();
                    int z = x/y;
                    s.push(z);
                }
                else if(operand=="*")
                {
                    int y = s.top();
                    s.pop();
                    int x = s.top();
                    s.pop();
                    int z = x*y;
                    s.push(z);
                }
                else
                {
                    s.push(stoi(operand));
                }
        }

        return s.top();
    }
};