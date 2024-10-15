string bin(long long NUMBER_TO_PRINT, int BITS_TO_PRINT = 16) {
    string BINARY_NUMBER = "";
    while (BITS_TO_PRINT--) {
        BINARY_NUMBER.push_back((NUMBER_TO_PRINT & 1) + '0');
        NUMBER_TO_PRINT >>= 1;
    }
    reverse(BINARY_NUMBER.begin(), BINARY_NUMBER.end());
    return BINARY_NUMBER;
}
