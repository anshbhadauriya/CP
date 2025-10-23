vector<pair<int,int>> vec = {{5,20},{1,10},{3,30},{2,40},{3,15}};


agar first value ko lekar sort karna hai too normal hai

sort(vec.begin(),vec.end());

agar second value ko lekar sort karna hai too use comparator like this-

sort(vec.begin(),vec.end(),[](auto &a,auto &b){
return a.second < b.second;
});

issi ko use krke hashmap ko sort kr skte ho by key or value!
