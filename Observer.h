//
// Created by Francesco Villi on 14/07/2020.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H
#include "Subject.h"

class Observer {
public:
    ~Observer();
    void update(Subject s)=0;
};


#endif //PROGRESSBAR_OBSERVER_H
