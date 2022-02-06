#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

bool fileExists(char* filename) {
    struct stat st;
    return stat(filename, &st) == 0;
}

// https://stackoverflow.com/questions/14424439/a-function-to-read-a-text-file
char *getFileContents(const char *filename) {
    long int size;
    FILE *file = fopen(filename, "r");

    if(!file) {
        fputs("File error.\n", stderr);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    char *result = (char *) malloc(size);
    if(!result) {
        fputs("Memory error.\n", stderr);
        fclose(file);
        return NULL;
    }

    if(fread(result, 1, size, file) != size) {
        fputs("Read error.\n", stderr);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return result;
}

int main() {
    struct passwd *pw = getpwuid(getuid());
    char *homeFile = pw->pw_dir;

    strcat(homeFile, "/.config/femboyde/config.fem");

    if (!fileExists(homeFile)) {
        printf("file no exist :(\n");
        return -1;
    }

    printf("file exists! reading...\n");

    char *result = getFileContents(homeFile);

    if(!result) return -1;

    printf("%s\n", result);
    free(result);

    return 0;
}
