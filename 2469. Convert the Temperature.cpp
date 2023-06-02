class Solution {
public:
    vector<double> convertTemperature(double celsius) 
    {
        vector<double> toreturn;
        toreturn.push_back(celsius + 273.15);
        toreturn.push_back((celsius*1.8)+32);
        return toreturn;
    }
};