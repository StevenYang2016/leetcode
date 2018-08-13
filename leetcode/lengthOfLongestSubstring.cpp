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
		//�ӷָ�㿪ʼ����
		int j = split_at;
		//Ŀ�����ҵ���Ĳ��ظ��Ĵ��Ľ�ֹλ��
		for (; j<i; j++) {
			if (chars[i] == chars[j]) {
				break;
			}
		}
		//���jС��i�Ļ���˵����ǰ�����ظ�������
		if (j < i) {
			//����ȷ���ָ����Ŀǰ�����һ����
			split_at = j + 1;
			//��ǰ�ظ��ĳ���Ϊi-j
			cur_len = i - j;
		}
		//���j=i�Ļ���˵����ǰû���ظ�����ĸ����Ҫ�ѵ�ǰ����++��
		else {
			cur_len++;
		}
		//�����ǰ���ȴ������ֵ�����滻��
		if (cur_len > max) max = cur_len;
	}
	return max;
}
