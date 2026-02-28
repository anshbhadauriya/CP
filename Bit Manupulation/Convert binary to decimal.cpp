int binaryToDecimal(string s) {
    int decimal = 0;

    for(char c : s) {
        decimal = decimal * 2 + (c - '0');
    }

    return decimal;
}
