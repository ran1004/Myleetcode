#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		char vis[256] = {0};
		int start, end, len;
		start = end = len = 0;
		vis[(int)s[0]] = 1;
		while(end < s.length()) {
			len = len > end-start+1? len : end-start+1;	
			end++;
			while(0 != vis[(int)s[end]]) {
				vis[(int)s[start]] = 0;
				start++;
			}
			vis[(int)s[end]] = 1;
		}
		return len;
	}
};

int lengthOfLongestSubstring(char *arr) {
	char vis[256] = {0};	
	int start, end, Maxlen;
	start = end = Maxlen = 0;
	vis[(int)arr[0]] = 1;
	while(0 != arr[end]) {
		Maxlen = Maxlen < end-start+1? end-start+1 : Maxlen;
		end++;
		while(vis[(int)arr[end]]) 
			vis[(int)arr[start++]] = 0;	
		vis[(int)arr[end]] = 1;
	}
	return Maxlen;
}
