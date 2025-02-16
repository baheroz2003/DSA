//intialise two different variable at different location
//move them wrt to constraint
//that can used as start and end point
//to check palindorme we can use
//dhyan se move krayae
//2sum jb sorted ho
//sometimes sort and then apply
//it will work according to your need
//count no of good partition
//in above question we use two pointers technqiue but storing the last index of element in map
// class Solution {
// public:
//     int M = 1e9 + 7;
//     int numberOfGoodPartitions(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> last_index; //number, last index

//         for (int i = 0; i < n; ++i) {
//             last_index[nums[i]] = i;
//         }

//         int i = 0;
//         int j = max(0, last_index[nums[0]]);

//         int result = 1;
//         while(i < n) {
//             if(i > j) { //we found one partition
//                 result = (result*2)%M;
//             }

//             j = max(j, last_index[nums[i]]);
//             i++;
//         }

//         return result;
//     }
// };
//reverse me bhi kaam aata
//slow and fast pointer hota hai