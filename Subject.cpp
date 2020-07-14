//
// Created by Francesco Villi on 14/07/2020.
//

#include "Subject.h"


const void Subject::attach(Observer *obs) {
    if(obs!=NULL)
        observers.push_front(obs);
}
const void Subject::detach(Observer *obs) {
    if(obs!=NULL)
        observers.remove(*obs);
}