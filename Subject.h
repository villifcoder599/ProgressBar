//
// Created by Francesco Villi on 14/07/2020.
//
#include "Observer.h"

#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H


class Subject {

private:
    std::list<Observer> observers;
protected:
    virtual ~Subject()=0;
public:
    Subject() {}

    const void attach(Observer *obs);
    const void detach(Observer *obs);
    void notify();
};


#endif //PROGRESSBAR_SUBJECT_H
