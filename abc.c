#include <stdio.h>
#include <string.h>

int minTimeToRevert(char* word, int k) {
    int len = strlen(word);

    for (int i = 1; i <= len; i++) {
        if (len % i == 0) {
            int j;
            for (j = 0; j < i; j++) {
                char temp = word[j];
                int l;
                for (l = j; l < len - i; l += i) {
                    word[l] = word[l + i];
                }
                word[l] = temp;
            }
            if (strcmp(word, "initial_state") == 0) {
                return i;
            }
        }
    }
    return -1; // Error: Could not revert to initial state
}

int main() {
    char word[] = "exampleword";
    int k = 3;

    int result = minTimeToRevert(word, k);

    if (result != -1) {
        printf("Minimum time to revert to initial state: %d seconds\n", result);
    } else {
        printf("Error: Could not revert to initial state\n");
    }

    return 0;
}
