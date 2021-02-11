//
// Created by Francesco Villi on 14/07/2020.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H


class Observer {
public:
    virtual void update()=0;
    virtual ~Observer()=default;
};


#endif //PROGRESSBAR_OBSERVER_H
