// //question
// //N bags sb me kuch candy hai
// //monk candy khayega
// //k-minutes hr minute ek bag
// //long long lelo overflow
// //hr baar whi uthao jimse candy jyada hai
// //multiset replacable with heap
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,k;
//         cin>>n>>k;
//         multiset<long,long>bags;
//         for(int i=0;i<k;i++)
//         {
//             long long candy_ct;
//             cin>>candy_ct;
//             bags.insert(candy_ct);
//         }
//         long long total_candies=0;
//         for(int i=0;i<k;i++)
//         {
//             auto last_it=(--bags.end());
//             long long candy_ct=*last_it;
//             total_candies+=candy_ct;
//             bags.erase(last_it);
//             bags.insert(candy_ct/2);
//         }
//     }
// }
// ---------------
// //nesting bhut important hai
// //map ke andar pair bhi daal skte ho
// //pair me comparison agar pehle dono same hai toh
// //dusre wale ke respect me osrt hota hai
// // //pehle jiska bada hai usme pehle wala hi bada hota hai
// // #include <bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     map<pair<string,string>,vector<int>>m;
// //     int n;
// //     cin>>n;
// //     for(int i=0;i<n;i++)
// //     {
// //         string fn,ln;
// //         int ct;
// //         cin>>fn>>ln>>ct;
// //         for(int j=0;j<ct;j++)
// //         {
// //            int x;
// //            cin>>x;
// //            m[{fn,ln}].push_back(x);
// //         }
// //     }
// //     for(auto &pr:m)
// //     {
// //         auto &full_name=pr.first; //p
// //         auto &list=pr.second; //vector
// //         cout<<full_name.first<<" "<<full_name.second;
// //         cout<<list.size()<<endl;
// //         for(auto &element:list)
// //         {
// //             cout<<element<<" ";
// //         }
// //         cout<<endl;
// //     }
// // }
// //marks de decreasing order me 
// //agar same toh lexigorgraphic order game
// //set me combine hojata hai isliye alaag same ko hi print ke liye multiset use kiya kro
// // #include <bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     map<int,multiset<string>>marks_map;
// //     int n;
// //     for(int i=0;i<n;i++)
// //     {
// //         int marks;
// //         string name;
// //         cin>>name>>marks;
// //         marks_map[marks].insert(name);
// //     }
// //     auto cur_it=--marks_map.end();
// //     while(true)
// //     {
// //         auto &students=(*cur_it).second;
// //         int marks=(*cur_it).first;
// //         for(auto student:students){
// //             cout<<student<<" "<<marks<<endl;
// //         }
// //     if(cur_it==marks_map.begin())
// //         break;
// //         cur_it--;
// //     }
// // }
// //marks ko -ve se multiply krdo phir aaghe se traverse kro
// // #include <bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     map<int,multiset<string>>marks_map;
// //     int n;
// //     for(int i=0;i<n;i++)
// //     {
// //         int marks;
// //         string name;
// //         cin>>name>>marks;
// //         marks_map[-1*marks].insert(name);
// //         for(auto& it:marks_map)
// //         {
// //             auto &students=it.second;
// //             auto &marks=it.first;
// //             for(auto student:students)
// //             {
// //                 cout<<student<<" "<<-1*marks<<endl;

// //             }

// //         }
// //     }
// //     return 0;
// // }

