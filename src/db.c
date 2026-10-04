#include "../include/db.h"
#include "../include/utils.h"
#include <stdio.h>

hash_t hash_table[28];
void create_ht(hash_t*);
void insert_ht(char* buf, int index);

int create_db(int argc, char** argv) {

    create_ht(hash_table);
    for (int i=1; i<argc; i++) {
        //Open file in "r" mode
        FILE *fp = fopen(argv[i], "r");
        if(fp==NULL) {
            printf("Error in opening file");
            return FAILURE;
        }

        char buf[WORD_SIZE];
        while (1) {
            if (feof(fp)) {
                break;
            }
            fscanf(fp,"%s ", buf);
            // printf("%s ", buf);
            if (buf[0] >= 'A' && buf[0] <= 'Z') {
                insert_ht(buf,buf[0]-'A');
            } else if(buf[0] >= 'a' && buf[0] <= 'z') {
                insert_ht(buf,buf[0]-'a');
            } else if(buf[0] >= '0' && buf[0] <= '9') {
                insert_ht(buf,26);
            } else {
                insert_ht(buf,27);
            }
        }
    }

    return SUCCESS;
}

void create_ht(hash_t* hash_table) {
    for (int i=0; i<28; i++) {
        (hash_table[i]).index=i;
        (hash_table[i]).link=NULL;
    }
}

void insert_ht(char* buf, int index) {
    if (hash_table[index].link == NULL) {
        //HT is Empty
    }
    printf("%d ", index);
}
