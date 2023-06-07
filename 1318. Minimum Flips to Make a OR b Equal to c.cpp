class Solution {
public:
    int minFlips(int a, int b, int c)
    { 
        int count = 0;
        int z = (a|b)^c;
        if(z==0)
        {
            return count;
        }
        count+=1; //initial one add

        //Normal Count
        while(z&=z-1)
        {
            count+=1;
        }

        //Jaha jaha 1 common waha ek aur extra add to yeh check karne ke liye ki kitte extra add karne hai
        z = a&b&((a|b)^c); //common 1(in a and b) that are changing waha ek extra add
        if(z==0)
        {
            return count;
        }
        else
        {
            count+=1; //initial one add of and
            while(z&=z-1)
            {
                count+=1;
            }
        }
        return count;

    }
};