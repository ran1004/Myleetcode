### 1. 两数之和
```html
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```


```cpp
class Solution {                                                                
public:                                                                         
    vector<int> twoSum(vector<int>& nums,int traget) {                          
        vector<int> arr(2, 0);                                                  
        map<int,int> hash;                                                      
        for(int i=0; i<nums.size(); i++) {                                      
            if(hash.count(traget-nums[i])) {                                    
                arr[0] = hash[traget-nums[i]], arr[1] = i;                      
                return arr;                                                     
            }                                                                   
            hash[nums[i]] = i;                                                  
                                                                                
        }                                                                       
        return arr;                                                             
    }                                                                           
};           

```
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> arr(2, -1);
		for(int i=0; i<nums.size()-1; i++) {
			for(int j=i+1; j<nums.size(); j++)	
				if(nums[i]+nums[j] == target) {
					arr[0] = i, arr[1] = j;	
					return arr;
				}
		}
		return arr;
	}
};
```
