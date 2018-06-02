#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define PRINT 0
#define NUM_WORDS 80800
#define NUM_LINES 3000
#define BUF 256

struct histogram
{
        char word[80];
        int freq;
};

char* chop(char *string)
{
    int i, len;
    len = strlen(string);
    char *newstring;

    newstring = (char *)malloc(len-1);

    for(i = 0; i < strlen(string)-1; i++){
        newstring[i] = string[i];
    }

    return newstring;
}

int check_word(char *token, struct histogram *histo, int max_words){

        int res=0;
        int i;

        for(i=0;i<max_words;i++){
             if(!strcmp(histo[i].word,token)){
                res = i;
            }
        }
        return res;
}

int main(int argv, char *argc[])
{
    int threads = *argc[2] - '0';
    omp_set_num_threads(threads); 
        FILE *fp;
        int i,k,j,l;
        int check;
        double exec_time;
        char *token;
        char buffer[BUF];
        struct histogram histo[NUM_WORDS];


        for(k=0;k<NUM_WORDS;k++)
                histo[k].freq = 0;

        char **lines = (char**)malloc(NUM_LINES*sizeof(char));

        for(k=0;k<NUM_LINES;k++){
                lines[k] = (char*)malloc(BUF * sizeof(char));
        }


        l=0;

        fp = fopen(argc[1], "r");

        while (fgets(buffer, sizeof(buffer), fp)!=NULL){
            lines[l] = chop(buffer);
            l++;
        }

        fclose(fp);

        i=0;
        exec_time = omp_get_wtime ( );
        int returned_index;
        
        #pragma omp parallel for schedule(static,200) private(returned_index,token,check) shared(histo)
        for(j=0; j < NUM_LINES ; j++){

            token = strtok(lines[j], " ");

            while (token != NULL){

                        check = check_word(token,histo,NUM_WORDS);

                        if(!check){
                            #pragma omp critical
                            {
                            strcpy(histo[i].word, token);
                            histo[i].freq=1;
                            }
                        }
                        else
                            #pragma omp critical
                            histo[check].freq++;

                        token = strtok(NULL, " ");
                        i++;
            }
        }

        exec_time = omp_get_wtime () - exec_time;

        if(PRINT){
          for(i=0;i<NUM_WORDS;i++)
                if(histo[i].freq > 1)
                    printf("%s: %d\n",histo[i].word,histo[i].freq);
        }

        printf ("Execution TIme: %12f\n", exec_time);
}
