#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    char word;
    string empty = "";
    vector<int> n;
    while(ss>>word)
    {
        empty += word;
        if(ss.peek()==',')
        {
            n.push_back(stoi(empty));
            empty = "";
            ss.ignore();
        }

    }
    n.push_back(stoi(empty));
    return n;
}

int main() {
    string str = "23,45,56";
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}