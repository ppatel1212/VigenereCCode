#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *wordList;
FILE *printedList;

//void decryptFunction(char *cipher, char *words);

int main(void){
    int i, j;
    char cipherText[1000];

    wordList = fopen("words.txt", "r");
    printedList = fopen("newWords.txt", "w");

    printf("Enter ciphertext: \n");
    scanf("%s", cipherText);


    for(i = 0; i < 1000; i ++){
        char keyPhrase[25], plain[10000];

        fscanf(wordList,"%s", keyPhrase);

        /*for(j=0; j < strlen(keyPhrase); j++){

            printf("%c", keyPhrase[j]);
        }

        printf("\n\n--------------------\n\n");*/

        //^ FOR LOOP ABOVE VERIFIED THAT THE KEYPHRASE VALUES ARE BEING READ IN
        

        for(j = 0; j < strlen(cipherText); j++){
            plain[j] = (((cipherText[j]-'a') - (keyPhrase[j%strlen(keyPhrase)]-'a')+26)%26) + 'a';
        }
        plain[j] = '\0';

        fprintf(printedList,"%s\n", plain);
    }

    /*for(j = 0; j < 1000; j++){

        fprintf(printedList,"%d: ", j+1);

        decryptFunction(cipherText, words[j]);
    }*/

    fclose(wordList);
    fclose(printedList);

    return 0;
}


/*void decryptFunction(char *cipher, char *words){
    int i, j, k;
    char plain[100000];


    for(i = 0; i < strlen(cipher); i++){
        plain[i] = (cipher[i] - words[i%strlen(words)]+26) % 26 + 'a';
        printf("\n\n\n%c\n\n", words[i]);
    }
    plain[i] = '\0';

    fprintf(printedList,"%s\n", plain);

}*/