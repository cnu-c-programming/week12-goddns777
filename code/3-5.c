#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";
    FILE* fp = fopen(filename, "r");
    
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        int val;
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, "%d", &val) == 1) {
            sum += val;
        } else {
            fprintf(stderr, "invalid input %s\n", line);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
