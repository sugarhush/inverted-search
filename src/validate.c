#include "../include/validate.h"
#include "../include/utils.h"
#include <stdio.h>

int validate_args(int argc,char** argv) {
    if (argc < 2) {
        printf("Usage: ./a.out <file_path>\n");
        return FAILURE;
    }
    return SUCCESS;
}
