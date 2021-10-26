#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

char **filenames;
int *filename_i_number;
DIR *opened_directory;
struct dirent *directory_pointer;
struct stat *statistics;
int amount_of_files = 0;
int main()
{
    opened_directory = opendir("tmp");
    filenames = malloc(sizeof(char) * 1024);
    filename_i_number = malloc(sizeof(int) * 1024);

    directory_pointer = readdir(opened_directory);
    while (directory_pointer)
    {
        stat(directory_pointer->d_name, statistics);
        filename_i_number[amount_of_files] = directory_pointer->d_ino;
        filenames[amount_of_files] = directory_pointer->d_name;

        amount_of_files++;
        directory_pointer = readdir(opened_directory);
    }

    for (int i = 0; i < amount_of_files; i++) {
        int the_same_i_number = 0;
        for (int j = 0; j < amount_of_files; j++) {
            the_same_i_number += filename_i_number[i] == filename_i_number[j];
            if (the_same_i_number >= 2) {
                printf("%s: ", filenames[i]);
                for (int l = 0; l < amount_of_files; l++) {
                    if (filename_i_number[i] == filename_i_number[l]) {
                        printf("%s, ", filenames[l]);
                    }
                }
                printf("\n");
            }
        }
    }
}