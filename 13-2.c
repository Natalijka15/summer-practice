#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char text[256], *words[256], *del = " .,!:;\t\r";

    printf("Enter text: ");
    fgets(text, 256, stdin);
    text[strlen(text) - 1] = 0;

    char *word = strtok(text, del);
    int n = 0;
    for (; word != NULL; word = strtok(NULL, del))
    {
        int len = strlen(word);
        if (len > 0) {
            words[n] = malloc(len + 1);
            strcpy(words[n++], word);
        }
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0 && strcmp(words[j], "0") != 0)
            {
                count++;
            	strcpy(words[j], "0");
	    } 
        }
	if (count > 1) printf("%s\n", words[i]);
    }

    return 0;
}