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


ProgressBar::ProgressBar(const wxString &title, const wxString &message, int maximum, wxWindow *parent, int style,
                         LoaderWxApp *l): wxProgressDialog(title, message, maximum, parent, style), loader(l) {}

void ProgressBar::update(int value) {
    this->Update(value);
}

