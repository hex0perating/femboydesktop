#pragma once
#include <stdbool.h>

bool fsUtils_fileExists(const char* filename);
char *fsUtils_getFileContents(const char *filename);
char *fsUtils_getConfPath();
char *fsUtils_getHomeDir();
char *fsUtils_replaceFileContents(const char *filename, const char *newContents);