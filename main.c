
#include "twofish.h"

int main()
{
    UINT *S;
    UINT K[40];
    int k;
    UINT QF[4][256];
    BYTE text[16];
    BYTE key[32];
    BYTE temp[16];
    printf("---------TEST\n");
    // Нулевой ключ, нулевой текст
    memset(text, 0, 16);
    memset(key, 0, 32);
    keySchedule(key, 128, &S, K, &k);
    fullKey(S, k, QF);
    free(S);
    memcpy(temp, text, 16);
    puts("BEFORE ENCRYPTING --->"); printHex(text, 16); printf("\n"); printf("\n");
    encrypt(K, QF, text);
    puts("AFTER ENCRYPTING ---->"); printHex(text, 16); printf("\n"); printf("\n");
    decrypt(K, QF, text);
    puts("AFTER DECRYPTING ---->"); printHex(text, 16); printf("\n"); printf("\n");
    for(int i = 0; i < 16; i++){
        if(i == 15){
            printf("Success\n");
        }
        else{
            if(text[i] == temp[i]) {
                printf("+");
            } else{
                printf("TROUBLE");
                break;
            }
        }
    }
    /*printf("\n S[0] = %lx, S[1] = %lx", S[0], S[1]);*/

    printSubkeys(K);
    printf("\n");

    // Второй тест, проверка целостности структуры
    printf("---------SECOND TEST\n");
    memcpy(key,  "\x9F\x58\x9F\x5C\xF6\x12\x2C\x32"
                 "\xB6\xBF\xEC\x2F\x2A\xE8\xC3\x5A", 16);
    memcpy(text, "\xD4\x91\xDB\x16\xE7\xB1\xC3\x9E"
                 "\x86\xCB\x08\x6B\x78\x9F\x54\x19", 16);
    memcpy(temp, text, 16);
    keySchedule(key, 128, &S, K, &k);
    fullKey(S, k, QF);
    free(S);
    printf("BEFORE ENCRYPTING --->"); printHex(text, 16); printf("\n"); printf("\n");
    encrypt(K, QF, text);
    printf("AFTER ENCRYPTING ---->"); printHex(text, 16); printf("\n"); printf("\n");
    decrypt(K, QF, text);
    printf("AFTER DECRYPTING ---->"); printHex(text, 16); printf("\n"); printf("\n");
    for(int i = 0; i < 16; i++){
        if(i == 15){
            printf("Success\n");
        }
        else{
            if(text[i] == temp[i]) {
                printf("+");
            } else{
                printf("TROUBLE");
                break;
            }
        }
    }
    printSubkeys(K);
    return 0;
}
#pragma clang diagnostic pop