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
			//if (nums[i] > target)
			//	continue;
			for (int j = i + 1; j != nums.size(); ++j) {
				//if (nums[j] > target)
				//	continue;
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

