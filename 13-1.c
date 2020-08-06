#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file1, *file2, *file3;

    file1 = fopen("file1.txt", "rt");
    if (!file1) return 1;
    
    file2 = fopen("file2.txt", "rt");
    if (!file2) return 1;
    
    file3 = fopen("file3.txt", "wt");
    if (!file3) return 1;

    while (!feof(file1) || !feof(file2)) {
        float tmp;
        if (fscanf(file1, "%f", &tmp)) {
            fprintf(file3, "%f\n", tmp);
        }
        if (fscanf(file2, "%f", &tmp)) {
            fprintf(file3, "%f\n", tmp);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}