### 4. 寻找两个有序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
```cpp
示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

```
```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = (nums1.size()+nums2.size())/2;		
		vector<int> myarr;
		int left, right;
		left = right = 0;
		while(left+right < len+1 
		&& left<nums1.size() && right<nums2.size()) {
			if(nums1[left] <= nums2[right])
				myarr.push_back(nums1[left++]);
			else
				myarr.push_back(nums2[right++]);
		}
		int cnt = left+right;
		while( left < nums1.size() && ++cnt <= len+1)
			myarr.push_back(nums1[left++]);
		while(right < nums2.size() && ++cnt <= len+1)
			myarr.push_back(nums2[right++]);
		
		return (nums1.size()+nums2.size())&1
			?	myarr[len] 
			:	(myarr[len]+myarr[len-1])/2;
	 }
};
```
