#ifndef HEADER_H
#define HEADER_H

#define SUCCESS 0
#define FAILURE -1
#define PATH_MAX 1024
#define WORD_SIZE 1024
#define FNAME_SIZE 64

typedef struct node {
    char filepath[PATH_MAX];
    struct node *link;
} filelist;

typedef struct sub {
    int word_count;
    char f_name[FNAME_SIZE];
    struct sub *link;
} subnode_t;

typedef struct main {
    int file_count;
    char word[WORD_SIZE];
    struct main *main_link;
    struct sub *sub_link;
} mainnode_t;

typedef struct ht {
    int index;
    struct node *link;
} hash_t;

#endif
