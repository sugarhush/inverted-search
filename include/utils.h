#ifndef HEADER_H
#define HEADER_H

#define SUCCESS 0
#define FAILURE -1
#define PATH_MAX 1024

typedef struct node {
    char filepath[PATH_MAX];
    struct node *link;
} filelist;
#endif
