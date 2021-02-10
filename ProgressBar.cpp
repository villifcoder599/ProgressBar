//
// Created by Francesco Villi on 15/07/2020.
//

#include "ProgressBar.h"
#include <utility>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/progdlg.h>

ProgressBar::ProgressBar(Subject *managerFile,wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size,
                         long style):wxGauge(parent,id,range,pos,size,style),managerFile(managerFile) {
    if(this->managerFile!=nullptr) {
        this->managerFile->attach(this);
    }
}

void ProgressBar::update(int value) {
    this->SetValue(value);
}

ProgressBar::~ProgressBar() {
    if (this->managerFile != nullptr)
        this->managerFile->detach(this);
}

