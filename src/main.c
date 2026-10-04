#include "../include/utils.h"
#include "../include/validate.h"
#include "../include/db.h"

int main(int argc, char** argv) {
    if(validate_args(argc, argv)==FAILURE) {
        return FAILURE;
    }
    create_db(argc, argv);
    return SUCCESS;
}
