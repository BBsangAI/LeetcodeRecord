from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i,j=0,len(nums)-1
        while i <= j:
           mid=(i+j)//2 #若为了防止溢出，可以用：mid=i + (i+j)//2
           if nums[mid]==target:
               return mid
           elif nums[mid]>target:
               j=mid-1
           else:
               i=mid+1
        return -1

