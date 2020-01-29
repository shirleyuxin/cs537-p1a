# cs537-p1a
This project has three files which are wis-grep.c, wis-tar.c, wis-untar.c
## wis-grep.c
This tool looks through a file, line by line, trying to find a user-specified search term in the line. If a line has the word within it, the line is printed out, otherwise it is not.

Using getline() to go through the file line by line and using strstr() to find if the line has the specified word.

## wis-tar.c
Write a new tar file based on the given txt files.

#### Part of the requirements
If any of the input file names are longer than 100 characters, you can only use the first 100 characters as the filename to store in the tar format.
If any of the input file names are shorter than 100 characters, you can pad the filename such that it uses 100 bytes. For example if the file name was “a.txt”, that only has 5 characters. In this case you can append 95 NULL i.e., \0 characters to make the name use 100 bytes in the tar file. (Remember '\0' is not the same as '0'. The first one represents NULL while the second one represents the character 0!)
===> Using strncpy()

## wis-untar.c
The wis-untar program will do the reverse of the wis-tar program which is to write txt files based on the given tar files.

Using fread() to read the file.
