#include "stdafx.h"
#include "twoSum.h"


twoSum::twoSum()
{
	int target=17,len;
	vector<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back(i);
	}
	vector<int> sumRet = getTarget(nums,target);
	len = sumRet.size();
	for (int j = 0; j < len; j++)
		cout << sumRet[j] << endl;

}


twoSum::~twoSum()
{
}


vector<int> twoSum::getTarget(vector<int>& nums, int target) {
	int len = nums.size();
	int sum;
	vector<int> ret;

	for (int i = 0; i < len; i++) {

			for (int j =i+1; j < len; j++) {

					sum = nums[i] + nums[j];
					if (sum == target) {
						ret.push_back(i);
						ret.push_back(j);

					}
			}
	}
	return ret;
}
