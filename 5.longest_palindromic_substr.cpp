#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindromicSubstring(string s) {
		string ret;
		for(int i=1; i<s.length()-1; i++) {
			int l = i;
			int r = i;
			while(s[r+1] == s[i]) ++r;
			if(r - l + 1 > ret.length())	
				ret.assign(s, l, r-l+1);
			while(l >= 0 && r < s.length()) {
				if(s[--l] == s[++r]) {
					if(r - l + 1 > ret.length())	
						ret.assign(s, l, r-l+1);
				}
				else 
					break;
			}
		}

		return ret;
	}
};


int main() {
	string str = "babad";
	cout << Solution().longestPalindromicSubstring(str) << endl;
}

