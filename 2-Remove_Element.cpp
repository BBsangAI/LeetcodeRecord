/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

你不需要考虑数组中超出新长度后面的元素。
*/
#include "iostream"
#include "vector"
using namespace std;

//=============================================//
//=================移除元素====================//
//=============================================//
class Remove_Element{
    public:
        // 暴力解法：时间复杂度O(n²)
        int Solution1(vector<int>& nums, int val){     //vector<int>封装的是一个类，而不是和数组那样 表示元素首地址，所以用&
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                    for (int j = i + 1; j < size; j++) {
                        nums[j - 1] = nums[j];
                    }
                    i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                    size--; // 此时数组的大小-1
                }
            }
            return size;
        }
        // 双指针法：时间复杂度：O(n)  都从数组的头开始
        int Solution2(vector<int>& nums, int val){
            int slowptr = 0;
            for(int fastptr=0; fastptr<nums.size();fastptr++){
                if(nums[fastptr] != val)
                    nums[slowptr++] = nums[fastptr];
            }
            return slowptr;
        }

};

//=============================================//
//================盛最多的水===================//
//=============================================//
class TheMost_Water{
    public:
        // 暴力解法：时间复杂度O(n²)
        int Solution1(vector<int>& heights){    
            int maxarea=0;
            //遍历数组，对每一组都计算容积，大的话进行更新
            for(int i=0;i<heights.size();i++)
                for(int j=i+1;j<heights.size();j++){
                    int tmparea=min(heights[i],heights[j])*(j-i);
                    maxarea=max(tmparea,maxarea);
                }
            return maxarea;
        }
        // 双指针法：时间复杂度O(n)  从数组两端开始
        int Solution2(vector<int>& heights){
            int slowptr = 0;
            int fastptr = heights.size() - 1;
            int MAX_V = min(heights[fastptr], heights[slowptr]) * (fastptr - slowptr);

            while(fastptr > slowptr){
                if(heights[fastptr] > heights[slowptr])
                    slowptr++;    // 保留更大的高度
                else 
                    fastptr--;
                int V = min(heights[fastptr], heights[slowptr]) * (fastptr - slowptr);
                MAX_V = max(V,MAX_V);
            }
            return MAX_V;
        }
};

int main(){
    Remove_Element S;
    TheMost_Water  S1;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    //int result = S.Solution2(nums, val);
    int result1 = S1.Solution2(nums);
    cout<<"result:"<<result1<<endl;

    return 0;
}