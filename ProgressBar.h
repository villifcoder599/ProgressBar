//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#include <wx/progdlg.h>
#include "Observer.h"
#include "LoaderWxApp.h"


#endif

class ProgressBar :public wxProgressDialog, Observer {

public:
    ProgressBar(const wxString& title, const wxString& message,
                int maximum = 100,
                wxWindow *parent = NULL,
                int style = wxPD_APP_MODAL | wxPD_AUTO_HIDE, LoaderWxApp *l=NULL);
    void update(int value);
protected:
    LoaderWxApp *loader;
};


#endif //PROGRESSBAR_PROGRESSBAR_H
