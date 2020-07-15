//
// Created by Francesco Villi on 14/07/2020.
//


#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H
#include <list>
#include "Observer.h"

class Subject {

protected:
    virtual ~Subject()=0;
public:
    Subject() {}

    const void attach(Observer *obs);
    const void detach(Observer *obs);
    void notify(*Subject s);

protected:
    std::list<Observer> observers{};
};


#endif //PROGRESSBAR_SUBJECT_H
