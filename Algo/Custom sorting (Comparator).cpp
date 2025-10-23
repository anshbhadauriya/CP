Normal sorting->

sort(v.begin(), v.end()); // uses a<b


Custom sorting->




sort(v.begin(), v.end(), [](int a, int b){
    return a > b;  // swap the rule
});

Example 2: Sorting a 2D vector by the 2nd element

Say you have:

vector<vector<int>> v = {{1, 5}, {3, 2}, {2, 4}};


You want to sort by the 2nd element of each subvector:

sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
    return a[1] < b[1]; // compare by 2nd element
});


? Output:

{3,2}, {2,4}, {1,5}


If you want descending by second element:

return a[1] > b[1];


?? Example 3: If 2nd element is same, sort by 1st element

This is where comparators shine ?

sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
    if (a[1] == b[1])
        return a[0] < b[0]; // then by first element
    return a[1] < b[1];     // primarily by second
});

