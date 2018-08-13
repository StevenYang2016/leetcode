#include "stdafx.h"
#include "lengthOfLongestSubstring.h"


lengthOfLongestSubstring::lengthOfLongestSubstring()
{
	string testString = "asdsfdhjssfj";
	int len=getLongestSubstring(testString);
	printf("The len of the string is %d",len);
}


lengthOfLongestSubstring::~lengthOfLongestSubstring()
{
}

int lengthOfLongestSubstring::getLongestSubstring(string str)
{
	const char * chars = str.c_str();
	int len = str.size();
	//getSubstring(mystr,len);

	//return 0;
	//char[] chars = s.toCharArray();
	if (2 > len) {
		return len;
	}
	int max = 0;
	int split_at = 0;
	int cur_len = 1;
	for (int i = 1; i<len; i++) {
		//从分割点开始查找
		int j = split_at;
		//目的是找到最长的不重复的串的截止位置
		for (; j<i; j++) {
			if (chars[i] == chars[j]) {
				break;
			}
		}
		//如果j小于i的话，说明当前包含重复的字了
		if (j < i) {
			//重新确定分割点在目前点的下一个。
			split_at = j + 1;
			//当前重复的长度为i-j
			cur_len = i - j;
		}
		//如果j=i的话，说明当前没有重复的字母，就要把当前长度++；
		else {
			cur_len++;
		}
		//如果当前长度大于最大值，则替换。
		if (cur_len > max) max = cur_len;
	}
	return max;
}
