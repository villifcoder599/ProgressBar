//
// Created by Francesco Villi on 14/07/2020.
//


#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H
#include <list>
#include "Observer.h"


class Subject {
public:
    virtual void attach(Observer *obs)=0;
    virtual void detach(Observer *obs)=0;
    virtual void notify(int i)=0;
protected:
    std::vector<Observer*> observers;
};


#endif //PROGRESSBAR_SUBJECT_H
