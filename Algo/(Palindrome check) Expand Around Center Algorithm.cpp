find palindromes inside a string efficiently.
used in questions like https://leetcode.com/problems/longest-palindromic-substring/
for(int i = 0; i < n; i++){

    // odd palindrome
    int l = i, r = i;
    while(l >= 0 && r < n && s[l] == s[r]){
        // process palindrome
        l--;
        r++;
    }

    //abh iss jagah l and r ek palindrome hai maximum size ka jiska mid i hogaa  (odd length) 
    // even palindrome
    l = i;
    r = i + 1;
    while(l >= 0 && r < n && s[l] == s[r]){
        // process palindrome
        l--;
        r++;
    }

     //abh iss jagah l and r ek palindrome hai maximum size ka jiska mid i hogaa  (even length) 
}
