#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // cycle through command arguments to list types
    for(int i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);

        struct stat file_stats;
        if(stat(argv[i], &file_stats) == -1) {
            printf("path error\n");
            continue;
        }

        // determine type from stats and print
        if(S_ISREG(file_stats.st_mode)) {
            printf("regular file\n");
        } else if(S_ISDIR(file_stats.st_mode)) {
            printf("directory\n");
        } else if(S_ISCHR(file_stats.st_mode)) {
            printf("character device\n");
        } else if(S_ISBLK(file_stats.st_mode)) {
            printf("block device\n");
        } else if(S_ISFIFO(file_stats.st_mode)) {
            printf("FIFO (named pipe)\n");
        } else if(S_ISLNK(file_stats.st_mode)) {
            printf("symbolic link\n");
        } else if(S_ISSOCK(file_stats.st_mode)) {
            printf("socket\n");
        } else {
            printf("path error\n");
        }
    }
    
    return 0;
}