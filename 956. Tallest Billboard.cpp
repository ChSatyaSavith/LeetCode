// class Solution {
// public:
//     int dp[21][2*5001];

//     int solve(vector<int> rods,int idx,int diff)
//     {
//         if(idx==rods.size())
//         {
//             return diff==0? 0:-1e4;
//         }

//         if(dp[idx][diff+5001]!=-1)
//         {
//             return dp[idx][diff+5001];
//         }

//         int op1 = rods[idx] + solve(rods,idx+1,diff + rods[idx]);
//         int op2 = solve(rods,idx+1,diff - rods[idx]);
//         int op3 = solve(rods,idx+1,diff);

//         return dp[idx][diff+5001] = max({op1,op2,op3});
//     }
//     int tallestBillboard(vector<int>& rods) 
//     {
//         memset(dp,-1,sizeof(dp));
//         return solve(rods,0,0);
//     }
// };

	class Solution {
	public:
		vector<unordered_map<int,int>> dp;
		int f(int i,vector<int>& v, int d){
			if(i==v.size()){
				if(d==0){
					return 0;
				}
			  return INT_MIN;
			}

			if(dp[i].find(d)!=dp[i].end())return dp[i][d];

			int x = f(i+1,v,d);
			int y = v[i] + f(i+1,v,d+v[i]);
			int z = f(i+1,v,d-v[i]);

			return dp[i][d] = max({x,y,z});
		}
		int tallestBillboard(vector<int>& rods) {
			dp.assign(21,{});
			return f(0,rods,0);

		}
	};