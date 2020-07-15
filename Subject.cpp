//
// Created by Francesco Villi on 14/07/2020.
//


#include "Subject.h"
#include "Observer.h"

const void Subject::attach(Observer *obs) {
    if(obs!= nullptr)
        observers.push_back(*obs);
}
const void Subject::detach(Observer *obs) {
    if(obs!=nullptr)
        observers.remove(*obs);
}

void Subject::notify(int *Subject) {
    for(auto item:observers){
        (item).update(this);
    }
}