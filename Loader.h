//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_LOADER_H
#define PROGRESSBAR_LOADER_H
#include "Subject.h"

class Loader:Subject {
public:
    Loader(int files);
    void transferAllFiles();
    int getFiles();
protected:
    int files;
};


#endif //PROGRESSBAR_LOADER_H
