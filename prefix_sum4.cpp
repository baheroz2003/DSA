//prefix sum sikh le bete
//suppose that mere pass ek number hai 1 2 3 4 5 6
//maanlo sb ko 0 0 0 0 0 0
//jha se jha tk chahiye
//0 2 0 -2 0 0
//ab prefix sum 0 2 2 0 0 0
//hashing bhi hai
//l-r replace a[l]+=k,a[r+1]-=k find prefix sum
//sidhi si paath hm aise krke prefix lenge toh required sum aajayega jo chahiye
//kya kro jaise tmhe chahiye ki itne se itne range me chahiye 
//start index +val krdo aur fir end+1 index pe -val krdo aur phir prefux sum nikaalo
long arrayManipulation(int n, vector<vector<int>>queries) {
       vector<long long>arr(n+2,0);
       for(auto x:queries){
        int st=x[0];
        int end=x[1];
        long long val=x[2];
        arr[st]+=val;
        arr[end+1]-=val;
       }
       for(int i=1;i<=n;i++){
        arr[i]=arr[i-1]+arr[i];
       }
       long long ans=*max_element(arr.begin(),arr.end());
       return ans;
       }

