class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        if(target>=letters[letters.size()-1])
        {
            return letters[0];
        }

        int left = 0;
        int right = letters.size()-1;
        char store;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(letters[mid]>target)
            {
                store = letters[mid];
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            
        }
        return store;
    }
};