//
// Created by Francesco Villi on 14/07/2020.
//


#include "Subject.h"

void Subject::attach(Observer *obs) {
    if(obs!= nullptr)
        observers.push_back(obs);
}
void Subject::detach(Observer *obs) {
    if(obs!=nullptr)
        observers.remove(obs);
}

void Subject::notify(int i) {
    for(auto item:observers)
        item->update(i);
}