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

ProgressBar::ProgressBar(wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size,
                         long style):wxGauge(parent,id,range,pos,size,style) {
}

void ProgressBar::update(int value) {
    this->SetValue(value);
}
