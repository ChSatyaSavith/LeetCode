class Solution {
public:
    vector<string> output;
    void backtrack(int start,map<char,string> phone,string temp,string digits)
    {
        if(start>=digits.length())
        {
            output.push_back(temp);
            return;
        }
        for(auto x:phone[digits[start]])
        {
            temp.push_back(x);
            backtrack(start+1,phone,temp,digits);
            temp.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits=="")
        {
            return output;
        }
        map<char,string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        string temp = "";
        backtrack(0,phone,temp,digits);
        return output;
    }
};