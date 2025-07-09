#include <stdio.h>
#include <string.h>

void compressRLE(char *input) {
    int count, i;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", input[i], count);
    }
    printf("\n");
}

void decompressRLE(char *input) {
    for (int i = 0; input[i] != '\0'; i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0';
        for (int j = 0; j < count; j++) {
            printf("%c", ch);
        }
    }
    printf("\n");
}

int main() {
    char str[] = "aaabbbbccdd";
    printf("Original: %s\n", str);
    printf("Compressed: ");
    compressRLE(str);

    char encoded[] = "a3b4c2d2";
    printf("Decompressed: ");
    decompressRLE(encoded);

    return 0;
}
