#include "../include/validate.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function Declarations
int insert_filepath(filelist **head, char* path);
void print_list(filelist* head);
int check_if_duplicate(filelist *head,char* path);


filelist *head = NULL;

int validate_args(int argc,char** argv) {
    if (argc < 2) {
        printf("Usage: ./a.out <file_path>\n");
        return FAILURE;
    }

    for (int i=1; i<argc; i++) {
        char* path = argv[i];
        if(strcmp(path+(strlen(path)-4),".txt") != 0) {
            return FAILURE;
        }

        FILE *fp = fopen(path, "r");
        if (fp == NULL) {
            printf("Error in opening file\n");
            return FAILURE;
        }

        if (check_if_duplicate(head,path)) {
            printf("Duplicate File Found : %s\n",path);
            return FAILURE;
        }

        if(insert_filepath(&head,path)==FAILURE) {
            return FAILURE;
        }
    }

    // print_list(head);
    return SUCCESS;
}

int insert_filepath(filelist **head, char* path) {

    filelist *new = malloc(sizeof(filelist));
    if (new==NULL) {
        printf("Error in new node creation\n");
        return FAILURE;
    }

    strcpy(new->filepath,path);
    new->link=NULL;

    if (*head==NULL) {
        *head=new;
        return SUCCESS;
    }

    filelist *temp = *head;
    while (temp->link!=NULL) {
        temp=temp->link;
    }
    temp->link=new;

    return SUCCESS;
}

void print_list(filelist* head) {
    while (head) {
        printf("%s ", head->filepath);
        head=head->link;
    }
}

int check_if_duplicate(filelist *head,char* path) {
    while (head) {
        if (strcmp(head->filepath, path)==0) {
            return 1;
        }
        head=head->link;
    }
    return 0;
}
