//
// Created by Francesco Villi on 14/07/2020.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H


class Observer {
public:
    ~Observer();
    virtual void update(int value)=0;
};


#endif //PROGRESSBAR_OBSERVER_H
