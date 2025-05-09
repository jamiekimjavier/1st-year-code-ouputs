#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int i;
    int letters = 0;
    int longestWord = 0;
    int words;

    printf("Enter the number of words: ");
    scanf("%d", &words);
    getchar();

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            letters++;
            if (letters > longestWord) {
                longestWord = letters;
            }
        } else {
            letters = 0;
        }
    }

        if (letters > longestWord) {
        longestWord = letters;
    }

    printf("The length of the longest word is: %d\n", longestWord);

    return 0;
}
