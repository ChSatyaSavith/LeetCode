class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> toreturn;
        if(strs.size()==1)
        {
            toreturn.push_back({strs[0]});
            return toreturn;
        }
        int n = strs.size();
        vector<bool> visited(n,false);

        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                string temp = strs[i];
                sort(temp.begin(),temp.end());
                vector<string> v;
                v.push_back(strs[i]);

                for(int j = 0;j<n;j++)
                {
                    if(!visited[j])
                    {
                        if(strs[j].length()==temp.length())
                        {
                            bool flag = true;
                            string temp1 = strs[j];
                            sort(temp1.begin(),temp1.end());
                            for(int k = 0;k<temp.length();k++)
                            {
                                if(temp[k]!=temp1[k])
                                {
                                    flag = false;
                                }
                            }
                            if(flag)
                            {
                                v.push_back(strs[j]);
                                visited[j] = true;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                toreturn.push_back(v);
            }
        }
        return toreturn;
    }
};