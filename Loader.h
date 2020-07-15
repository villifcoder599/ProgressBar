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
class Loader: public wxApp,public Subject {
protected:
    ProgressBar *dialog;
public:
    Loader(int files);
    Loader();
    void transferAllFiles();
    int getFiles();
    void notify(int i);
protected:
    //ProgressBar *dialog;
    int files;
};


#endif //PROGRESSBAR_LOADER_H
