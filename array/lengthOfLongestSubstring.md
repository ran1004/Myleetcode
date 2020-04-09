###3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
```html
示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```
```cpp
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
```

```c
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
```
