//
// Created by Francesco Villi on 15/07/2020.
//
//#include "gtest/gtest.h"
#include "ProgressBar.h"
#include <utility>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/progdlg.h>

ProgressBar::ProgressBar(ManagerFile *managerFile,wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size,
                         long style):wxGauge(parent,id,range,pos,size,style),managerFile(managerFile) {
    if(this->managerFile!=nullptr)
        this->managerFile->attach(this);
}

void ProgressBar::update() {
    int value=managerFile->getAllPaths().GetCount();
    if(value!=this->GetRange())
        this->SetRange(value);
    this->SetValue(managerFile->getLoadPaths());
    if(value==managerFile->getLoadPaths()) {
        wxMessageBox("Caricamento completato","Messaggio");
        this->SetRange(0);
    }
}

ProgressBar::~ProgressBar() {
    if (this->managerFile != nullptr)
        this->managerFile->detach(this);
}



