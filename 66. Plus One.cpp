class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        reverse(digits.begin(),digits.end());
        int carry = 0;
        bool flag = false;
        digits[0] += 1;
        if(digits[0]>=10)
        {
            digits[0] %= 10;
            carry = 1;
            flag = true;
        }
        else
        {
            carry = 0;
        }
        for(int i = 1;i<digits.size();i++)
        {
            flag = false;
            digits[i] += carry;

            if(digits[i]>=10)
            {
                digits[i] %= 10;
                carry = 1;
                flag = true;
            }
            else
            {
                carry = 0;
            }
        }
        if(flag)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;  
    }
};