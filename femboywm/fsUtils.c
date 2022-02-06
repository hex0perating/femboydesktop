#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

#include "fsUtils.h"

bool fsUtils_fileExists(const char* filename) {
    struct stat st;
    return stat(filename, &st) == 0;
}

// https://stackoverflow.com/questions/14424439/a-function-to-read-a-text-file
char *fsUtils_getFileContents(const char *filename) {
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

char *fsUtils_replaceFileContents(const char *filename, const char *newContents) {
    FILE *file = fopen(filename, "w");
    if(!file) {
        fputs("File error.\n", stderr);
        return NULL;
    }

    fputs(newContents, file);
    fclose(file);
    return NULL;
}

char *fsUtils_getConfPath() {
    struct passwd *pw = getpwuid(getuid());
    char *homeFile = pw->pw_dir;

    strcat(homeFile, "/.config/femboyde/femboywm.fem");

    return homeFile;
}

char *fsUtils_getHomeDir() {
    struct passwd *pw = getpwuid(getuid());
    char *homeDir = pw->pw_dir;

    return homeDir;
}