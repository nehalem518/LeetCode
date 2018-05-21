#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
	struct CNum{
		int num;
		int index;
	};

	static int cmp(CNum a, CNum b)
	{
		return a.num < b.num;
	}

public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		result.clear();

		vector<CNum> vecNumbers;
		for (auto i = 0; i != nums.size(); ++i) {
			CNum temp;
			temp.index = i;
			temp.num = nums[i];
			vecNumbers.push_back(temp);
		}

		sort(vecNumbers.begin(), vecNumbers.end(), &cmp);

		auto iStart = vecNumbers.begin();
		auto iEnd = vecNumbers.end() - 1;

		while (iStart != iEnd) {
			if ((*iStart).num + (*iEnd).num < target)
				iStart++;
			else if ((*iStart).num + (*iEnd).num > target)
				iEnd--;
			else {
				result.push_back((*iStart).index);
				result.push_back((*iEnd).index);
				break;
			}
		}
		return result;
	}
};

//
//int main()
//{
//	vector<int> ivec = { 0, 4, 3, 0 };
//	Solution s;
//	vector<int> result = s.twoSum(ivec, 0);
//	for (auto i : result) {
//		cout << i << endl;
//	}
//}