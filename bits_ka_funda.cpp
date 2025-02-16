//know how to convert any number to binary form
//function which converts decimal to binary
// string d2b(int n)
// {   string res="";
//     while(n)
//     {
//       res+=n%2;
//       n/=2;
//     }
//     reverse(res(begin),res(end));
//     return res;
// }
//s[i]*pow(2,n-i-1);
//last bit will tell u the sign
//2's complement of pos will give -ve
//-2^31=INT_MIN
//2^31=INT_MAX
//swap without using temp using xor u can do
//think about it
//how to check ith bit is set or not
//jo bhi position check krna utna shift krke and leke check krlo
//ya right shift krke and lo 1 ke saath
//to set ith bit use n or operator(1<<i )
//n&negation(1<<i) to clear the bit
//to toggle use xor operator
//remove the last set bit do N&N-1
//to check power of 2 or not
//bhai bhut saare inbuilt function hai c++ me for bits
//built_in_popcount
//subset function using bits
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int size=pow(2,nums.size());
//         vector<vector<int>>result;
//         for(int i=0;i<size;i++)
//         {
//             vector<int>list;
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(i&(1<<j))
//                 {
//                   list.push_back(nums[j]);
//                 }
//             }
//             result.push_back(list);
//         }
//         return result;
//     }
// };
