/*  
    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

    示例 1:

    输入: nums = [-1,0,3,5,9,12], target = 9     
    输出: 4       
    解释: 9 出现在 nums 中并且下标为 4     
    示例 2:

    输入: nums = [-1,0,3,5,9,12], target = 2     
    输出: -1        
    解释: 2 不存在 nums 中因此返回 -1        
    提示：

    你可以假设 nums 中的所有元素是不重复的。
    n 将在 [1, 10000]之间。
    nums 的每个元素都将在 [-9999, 9999]之间。
*/

/*二分查找条件： 数组为有序数组，且数组中无重复元素*/

#include "iostream"
#include "vector"
using namespace std;
//======时间复杂度O(Log(N))=========//
class Binary_Search{
    public:
        int Solution(vector<int>& nums, int target)
        {
          int left = 0;
          int right = nums.size() - 1;
          int mid = 0;
          while(left <= right){
            mid = left + ((right-left) >> 1);   //数据溢出也能用，且比/2快
            if(nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
          }
          return -1;
        }
};

//======时间复杂度O(N)=========//
// class Binary_Search{
//     public:
//         int Solution(vector<int>& nums, int target)
//         {
//             for (int i = 0; i < nums.size(); i++){
//                 if(nums[i] == target)
//                     return i;
//             }
//             return -1;
//         }
// };

int main()
{
    Binary_Search S;             
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 0; 
    int result = S.Solution(nums, target);
    cout<<"result:"<<result<<endl;

    return 0;
}