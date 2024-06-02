#include<iostream>
using namespace std;
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int p1=0;
        int p2=0;
        int i=0;
        while(i<nums1.size()+nums2.size()){
            if(p1 !=nums1.size() && p2!=nums2.size()){
                if(nums1[p1] >nums2[p2] ){
                    nums3.push_back(nums2[p2++]);
                }
                else{
                    nums3.push_back(nums1[p1++]);
                }
            }
            
        }
        if(p1 !=nums1.size()){
            nums3.push_back(nums1[p1++]);
        }
        if(p2 != nums2.size()){
            nums3.push_back(nums2[p2++]);
        }
        int a= nums3.size() /2;
        if(nums3.size() & 2 ){
             return nums3[a];
           
        }
    return (nums3[a]+nums3[a-1])/2;
   

    }
};

int main(){
   
    vector<int> num1 , num2;
    num1.push_back(1);
    num1.push_back(3);
    num2.push_back(2);
    Solution s= Solution();
    cout<<s.findMedianSortedArrays(num1,num2);
    
}