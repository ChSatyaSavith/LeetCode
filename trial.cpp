#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> func_calls;

void recursion(int previous,int current,int sum,vector<int> line1,vector<int> line2,int players)
{
    if(previous!=current)
    {
        int max = -1;
        for(int i = previous+1;i<current;i++)
        {
            if(line2[i]>max)
            {
                max = line2[i];
            }
        }
        sum = sum + max;
    }
    if(current == players-2)
    {
        sum += line2[current+1];
    }
    for(int i = current+2;i<players;i++)
    {
        recursion(current,i,sum+line1[i],line1,line2,players);
    }
    func_calls.push_back(sum);
}

void recursion1(int previous,int current,int sum,vector<int> line1,vector<int> line2,int players)
{
    if(previous!=current)
    {
        int max = -1;
        for(int i = previous+1;i<current;i++)
        {
            if(line1[i]>max)
            {
                max = line2[i];
            }
        }
        sum = sum + max;
    }
    if(current == players-2)
    {
        sum += line1[current+1];
    }
    for(int i = current+2;i<players;i++)
    {
        recursion(current,i,sum+line2[i],line1,line2,players);
    }
    func_calls.push_back(sum);
}
int main()
{
    vector<int> line1 = {9,3,5,7,3};
    vector<int> line2 = {1,8,9,4,5};
    recursion(0,0,line1[0],line1,line2,5);
    recursion(0,0,line2[0],line1,line2,5);
    cout<<*max_element(func_calls.begin(),func_calls.end())<<endl;
}