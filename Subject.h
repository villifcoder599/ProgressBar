//
// Created by Francesco Villi on 14/07/2020.
//


#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H
#include <vector>
#include "Observer.h"
#include <list>

class Subject {
public:
    virtual void attach(Observer *obs)=0;
    virtual void detach(Observer *obs)=0;
    virtual void notify()=0;
    virtual ~Subject()=default;
protected:
    std::list<Observer*> observers;
};


#endif //PROGRESSBAR_SUBJECT_H
