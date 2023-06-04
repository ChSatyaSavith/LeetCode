class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int province = 0;
        vector<bool> visited(isConnected.size(),false);
        
        for(int i = 0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                province+=1;
                stack<int> st;

                st.push(i);
                while(!st.empty())
                {
                    int temp = st.top();
                    st.pop();
                    visited[temp] = true;

                    for(int j = 0;j<isConnected.size();j++)
                    {
                        if(isConnected[temp][j]!=0 && !visited[j])
                        {
                            st.push(j);
                        }
                    }
                }
            }
            else
            {
                continue;
            }
        }
        return province;
    }
};