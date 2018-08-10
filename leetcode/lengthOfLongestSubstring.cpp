#include "stdafx.h"
#include "lengthOfLongestSubstring.h"


lengthOfLongestSubstring::lengthOfLongestSubstring()
{
}


lengthOfLongestSubstring::~lengthOfLongestSubstring()
{
}

int lengthOfLongestSubstring::getLongestSubstring(string str)
{
	const char * mystr = str.c_str();
	int len = str.size();
	getSubstring(mystr,len);

	return 0;
}

int lengthOfLongestSubstring::getSubstring(const char* str,int len)
{
	char first = str[0];
	for (int i = 1; i < len; i++) {
		if (first == str[i]) {
			char *temp = (char *)malloc(i - 1);
			memcpy(temp, str + 1, i - 1);
			getSubstring(temp, i - 1);
			break;
		}

	}
	return 0;
}
