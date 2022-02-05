// THIS IS THE WORST CODE YOU WILL EVER SEE. don't touch it.
// - Creamy

#include "motherfucker.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#define chunk 4096

int startsWith(const char *a, const char *b) {
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

char* motherfucker() {
    srand(time(NULL));

    int searchLen = 6;

    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;

    char *buf = malloc(chunk);
    FILE *file;
    size_t nread;

    file = fopen(strcat (homedir, "/list"), "r");

    fseek(file, 0L, SEEK_END);
    long int res = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (buf == NULL) {
        return("gay ass code no work :(");
    }

    if (file) {
        while ((nread = fread(buf, 1, chunk, file)) > 0) {
            long int tempRes = ftell(file);

            if (!tempRes > res) {
                fwrite(buf, 1, nread, stderr);
            }
        }
        
        if (ferror(file)) {
            return("your retar");
        }
        
        fclose(file);
    }

    char * token = strtok(buf, "\n");

    int currentSearchArea = 0;

    while(token != NULL) {
      int r = rand();
      if (searchLen != currentSearchArea) {
          if (r % 2 == 1) {
              return token;
              break;
          }
      } else {
          break;
      }
      currentSearchArea++;

      token = strtok(NULL, "\n");
    }

    return("nya~");
}