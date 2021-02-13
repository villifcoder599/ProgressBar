//
// Created by Francesco Villi on 15/07/2020.
//

#include "ProgressBar.h"


ProgressBar::ProgressBar(ManagerFile *managerFile,wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size,
                         long style):wxGauge(parent,id,range,pos,size,style),managerFile(managerFile){
    if(this->managerFile!=nullptr)
        this->managerFile->attach(this);
}

void ProgressBar::update() {
    this->SetValue(managerFile->getLoadPaths());
}

ProgressBar::~ProgressBar(){
    if (this->managerFile != nullptr)
        this->managerFile->detach(this);
}

void ProgressBar::setRange(int r) {
    SetRange(r);
}

void ProgressBar::setValue(int value) {
    SetValue(0);
}



