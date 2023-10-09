#include <vector>
#include <iostream>
using namespace std;

int main()
{
    string s = "PAYPALISHIRING";
    vector<vector<char>> store(3);
    for(int i = 0;i<3;i++)
    {
        vector<char> temp;
        store.push_back(temp);
    }
    bool straight = true;
    int j = 0;
    for(int i = 0;i<s.size();i++)
    {
        if(j<3 && straight)
        {
            store[j].push_back(s[i]);
            j+=1;
            if(j==3)
            {
                straight = false;
                j-=2;
            }
        }
        else
        {
            store[j].push_back(s[i]);
            j-=1;
            if(j<0)
            {
                straight = true;
                j+=2;
            }
        }
    }
    string toreturn = "";
    for(auto x: store)
    {
        for(auto y: x)
        {
            toreturn.push_back(y);
        }
    }
    cout<<toreturn<<endl;
}