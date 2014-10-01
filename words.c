#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Please input your letters as one word");
        return 1;
    }

    char *word = argv[1];
    int length = (int)strlen(word);
    int *hit = (int*)malloc(sizeof(int)*length);
    int i, j, flag, allflag;
    for(i = 0; i < length; i++)
        hit[i] = 0;

    char line[100]; //a line should be no more than 100 characaters

    FILE *f = fopen("words.txt", "rt");

    //first look for all words containing only the given letters in word.
    printf("Looking for words up to %d letters containing the letters of %s:\n", length, word);
    while(fgets(line, 100, f) != NULL) {
        line[strlen(line)-1] = '\0'; //need to remove \n character.
        if(strlen(line) <= length) {
            allflag = 1;
            for(i = 0; i < strlen(line) && allflag == 1; i++) {
                flag = 0;
                for(j = 0; j < length && !flag; j++) {
                    if((line[i] == word[j] || word[j] == '*') && hit[j] == 0) {
                        hit[j] = 1;
                        flag = 1;
                    }
                }
                if(!flag) {
                    allflag = 0;
                }
            }
            if(allflag) {
                printf("%s\n",line);
            }
            for(i = 0; i < length; i++) {
                hit[i] = 0;
            }
        }
    }

    fclose(f);

    return 0;
}
