#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{

public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> res;
		unordered_map<int, int> hashNums;
		for (auto i = 0; i != nums.size(); i++)	{
			hashNums[nums[i]] = i;
		}

		for (auto i = 0; i != nums.size(); i++) {
			int t = target - nums[i];
			if (hashNums.count(t) && hashNums[t] != i) {
				res.push_back(i);
				res.push_back(hashNums[t]);
				break;
			}
		}

		return res;
	}
};

//int main()
//{
//	vector<int> ivec = { 0, 4, 3, 0 };
//	Solution s;
//	vector<int> result = s.twoSum(ivec, 0);
//	for (auto i : result) {
//		cout << i << endl;
//	}
//}