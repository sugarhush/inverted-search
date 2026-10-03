#include "../include/utils.h"
#include "../include/validate.h"

int main(int argc, char** argv) {
    if(validate_args(argc, argv)==FAILURE) {
        return FAILURE;
    }
    return SUCCESS;
}
