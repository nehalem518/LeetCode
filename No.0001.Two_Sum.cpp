#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		result.clear();
		for (int i = 0; i != nums.size(); ++i) {
			for (int j = i + 1; j != nums.size(); ++j) {
				if ((nums[i] + nums[j]) == target) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};


//int main()
//{
//	vector<int> ivec = { 0, 4, 3, 0 };
//	Solution s;
//	vector<int> result = s.twoSum(ivec, 0);
//}