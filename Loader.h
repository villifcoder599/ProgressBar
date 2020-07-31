//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_LOADER_H
#define PROGRESSBAR_LOADER_H

#include "Subject.h"
#include "ProgressBar.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/progdlg.h>

class ProgressBar;
class Loader: public wxApp,Subject {
protected:
    ProgressBar *dialog;
public:
    Loader(int files=1);
    bool OnInit();
    int getFiles();
    void notify(int i);
    void attach(Observer *obs);
    void detach(Observer *obs);
protected:
    //ProgressBar *dialog;
    int files;
};



#endif //PROGRESSBAR_LOADER_H
