class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        int first = 0;
        int last = costs.size()-1;

        long long toreturn = 0;
        priority_queue<int, vector<int>, greater<int>> p1;
        priority_queue<int, vector<int>, greater<int>> p2;

        while(k--)
        {
            while(p1.size()<candidates && first<=last)
            {
                p1.push(costs[first++]);

            }
            while(p2.size()<candidates && first<=last)
            {
                p2.push(costs[last--]);

            }

            int t1 = p1.size()>0 ? p1.top() : INT_MAX;
            int t2 = p2.size()>0 ? p2.top() : INT_MAX;

            if(t1<=t2)
            {
                toreturn += t1;
                p1.pop();
            }
            else
            {
                toreturn += t2;
                p2.pop();
            }

        }

        return toreturn;
    }
};