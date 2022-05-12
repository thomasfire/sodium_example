//
// Created by thomasf on 22/05/12.
//

#include "sodium.h"

#include <string.h>
#include <stdio.h>

#ifndef PRINT_HEX
#define PRINT_HEX 1
#endif

int main(int argc, const char **argv) {
    if (argc != 2) {
        printf("Usage: $ %s STRING_TO_HASH", argv[0]);
        exit(1);
    }

    char hash[crypto_generichash_BYTES];

#if PRINT_HEX
    char hex[crypto_generichash_BYTES * 2 + 1];
#endif

    crypto_generichash(hash, sizeof(hash), argv[1], strlen(argv[1]), NULL, 0);

#if PRINT_HEX
    printf("%s", sodium_bin2hex(hex, sizeof(hex), hash, sizeof(hash)));
#else
    printf("%s", hash);
#endif

    return 0;
}