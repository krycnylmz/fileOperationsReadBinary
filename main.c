#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct {
    int film_id;
    char title[255];
    char description[1023];
    unsigned int release_year;
    char rental_duration;
    float rental_rate;
    unsigned char length;
    float replacement_cost;
    char rating[10];
    char last_update[30];
} RECORD_t, *RECORD;


void print_movie(RECORD_t rec) {
    printf("ID: %d\n", rec.film_id);
    printf("TITLE: %s\n", rec.title);
    printf("DESCRIPTION: %s\n", rec.description);
    printf("RELEASE YEAR: %d\n", rec.release_year);
    printf("RENTAL DURATION: %d\n", rec.rental_duration);
    printf("RENTAL RATE: %f\n", rec.rental_rate);
    printf("REPLACEMENT COST: %f\n", rec.replacement_cost);
    printf("RATING: %s\n", rec.rating);
    printf("LAST UPDATE: %s\n", rec.last_update);
    printf("\n");
}

void print_all_movies(RECORD rec, int n) {
    int i;
    for (i = 0; i < n; i++) {
        print_movie(rec[i]);
    }
}


int main() {
    int searching_id;

/*
    printf("Please type the ID which is you want to search...\n");

    scanf("%d", &searching_id);

    printf("Please wait until find the movie depending on id: %d\n",searching_id);
*/


/*    int * film_id;

    FILE *movies;
    movies = fopen("sorted.bin","rb");
    fseek( movies, 0, SEEK_SET);
    fread(&film_id,sizeof(int) * 1,1,movies);
    printf("okunan id: %d \n",(int)film_id);
    fclose(movies);*/



    RECORD movies1_records = (RECORD)malloc(sizeof(RECORD_t) * 2);
    FILE *movies1_file = fopen("sorted.bin", "rb");
    if (movies1_file == NULL) {
        printf("Cannot open the sorted.bin file.\n");
        exit(1);
    }
    fread(movies1_records, sizeof(RECORD_t) * 1, 1, movies1_file);

    print_all_movies(movies1_records,1);
    fclose(movies1_file);



int ch;
int is_find = 0;
FILE *fp;
fp = fopen("sorted.bin","r");
    ch = getc(fp);
    printf("\n %d",ch);
    fseek(fp,0,SEEK_SET);
    fseek(fp,6,SEEK_CUR);
    ch = getc(fp);
    printf("\n %d",ch);
    if (ch == 65){
        printf("Koray");
    }


/*while(is_find != 1){
    ch = getc(fp);
    if(ch == 1){
        is_find ==1;
    }
    printf("\n %d",ch);
}*/



    return 0;
}
