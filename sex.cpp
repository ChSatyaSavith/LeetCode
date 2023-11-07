#include <iostream>
using namespace std;

int main()
{
    string string1 = "comiccomedy";
    int count = 0;
    for(int i = 0;i<string1.length();i++)
    {
        bool flag = true;
        for(int j = 0;j<string1.length();j++)
        {
            if(i==j)
            {
                continue;
            }
            if(string1[i]==string1[j])
            {
                flag = false;
            }
        }
        if(flag)
        {
            count++;
        }
    }
    cout<<count<<endl;
}

