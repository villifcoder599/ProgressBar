//
// Created by Francesco Villi on 15/07/2020.
//

#include "ProgressBar.h"


ProgressBar::ProgressBar(ManagerFile *managerFile,wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size,
                         long style):wxGauge(parent,id,range,pos,size,style),managerFile(managerFile){
    if(this->managerFile!=nullptr)
        managerFile->attach(this);
}

void ProgressBar::update() {
    SetValue(managerFile->getLoadPaths());
}

ProgressBar::~ProgressBar(){
    if (managerFile != nullptr)
        managerFile->detach(this);
}

void ProgressBar::setRange(int r) {
    SetRange(r);
}

void ProgressBar::setValue(int value) {
    SetValue(0);
}



