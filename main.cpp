#include <iostream>

int key_gen1(char* username) {
    signed int v5 = 1423243;
    char v1;
    char v3;
    char *i;

    for (i = username; *i; ++i) {
        v3 = *i;
        if (*i <= 109) {
            v1 = (v3 ^ 0x65) + 32;
        } else {
            v1 = (v3 ^ 0x66) - 16;
        }
        v5 += v1;
    }
    return v5 ^ 0xF0DAF;
}

int key_gen2(char* username) {
    int v1; // ST14_4
    int v2; // ST18_4
    int v4; // [esp+10h] [ebp-18h]
    int v5; // [esp+14h] [ebp-14h]
    int v6; // [esp+18h] [ebp-10h]
    char *v7; // [esp+1Ch] [ebp-Ch]

    v7 = username;
    v6 = 0;
    v5 = 0;

//    BYTE2(v4) = -119;
//    BYTE1(v4) = -22;
//    HIBYTE(v4) = 0;
//    int b1 = -119;
//    int b2 = -22;
    int b3 = 0;

    while ( *v7 )
    {
//        LOBYTE(v4) = *v7;
//        char b4 = *v7;

        v1 = 32 * b3 + v5;
        v2 = (v1 - *v7) ^ 0x89;
        v5 = v1 - 22;
        v6 = v2 + 55;
        b3 = *v7++;
    }
    std::cout << abs(v6) << '-' << abs(v5) << std::endl;
    return 0;
}

int main() {
    char* username;

    std::cin >> username;
    std::cout << std::endl;

    std::cout << "keygen1: " << key_gen1(username) << std::endl;
    std::cout << "keygen2: " << key_gen2(username) << std::endl;

    return 0;
}