//
// Created by Francesco Villi on 15/07/2020.
//

#include <unistd.h>
#include <cstdlib>
#include "Loader.h"

Loader::Loader(int files) {
    this->files=files;
}

void Loader::transferAllFiles() {
    for(int i=0;i<files;i++){
        sleep(600+rand()%400);
        notify(this);
    }
}
