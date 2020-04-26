#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindromicSubstring(string s) {
		string ret;	
		int l = 0, start = 0, end = 0, len = 0, g_start = 0;
		while(l < s.length()) {
			start = l, end = l;	
			while(end<s.length()-1 && s[end+1] == s[l])
				end++;
			l = end+1;
			while(start > 0 && end<s.length()-1 && s[start-1] == s[end+1])
				--start, ++end;
			if(end - start +1 > len) {
				len = end - start + 1;
				g_start = start;
			}
		}

		ret.assign(s, g_start, len);
		return ret;
	}
};


int main() {
	string str = "babad";
	cout << Solution().longestPalindromicSubstring(str) << endl;
	cout << "today is a good day ^_^ " << endl;
}

