find palindromes inside a string efficiently.

for(int i = 0; i < n; i++){

    // odd palindrome
    int l = i, r = i;
    while(l >= 0 && r < n && s[l] == s[r]){
        // process palindrome
        l--;
        r++;
    }

    // even palindrome
    l = i;
    r = i + 1;
    while(l >= 0 && r < n && s[l] == s[r]){
        // process palindrome
        l--;
        r++;
    }
}
