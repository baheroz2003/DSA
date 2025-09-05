#include <bits/stdc++.h>
using namespace std;

// ---------- Activity Selection ----------
int activitySelection(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int,int>> act;
    for(int i=0;i<n;i++) act.push_back({end[i], start[i]});
    sort(act.begin(), act.end()); // sort by end time
    
    int cnt=1, lastEnd=act[0].first;
    for(int i=1;i<n;i++){
        if(act[i].second > lastEnd){
            cnt++; lastEnd=act[i].first;
        }
    }
    return cnt;
}

// ---------- Job Sequencing ----------
struct Job { int profit, deadline; };
int jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){ return a.profit > b.profit; });
    int maxD=0; for(auto &j: jobs) maxD=max(maxD,j.deadline);
    vector<int> slot(maxD+1,-1);
    int profit=0;
    for(auto &j: jobs){
        for(int d=j.deadline; d>0; d--){
            if(slot[d]==-1){ slot[d]=j.profit; profit+=j.profit; break; }
        }
    }
    return profit;
}

// ---------- Fractional Knapsack ----------
struct Item { int val, wt; };
double fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), [](Item &a, Item &b){
        return (double)a.val/a.wt > (double)b.val/b.wt;
    });
    double ans=0;
    for(auto &it: items){
        if(W>=it.wt){ ans+=it.val; W-=it.wt; }
        else{ ans+=(double)it.val*W/it.wt; break; }
    }
    return ans;
}

// ---------- Main ----------
int main() {
    // Activity Selection
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end   = {2,4,6,7,9,9};
    cout << "Activity Selection: " << activitySelection(start,end) << "\n";

    // Job Sequencing
    vector<Job> jobs = {{100,2},{19,1},{27,2},{25,1},{15,3}};
    cout << "Job Sequencing Profit: " << jobSequencing(jobs) << "\n";

    // Fractional Knapsack
    vector<Item> items = {{60,10},{100,20},{120,30}};
    int W=50;
    cout << "Fractional Knapsack: " << fractionalKnapsack(items,W) << "\n";

    return 0;
}
