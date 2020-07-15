//
// Created by Francesco Villi on 15/07/2020.
//

#include <unistd.h>
#include <cstdlib>

#include "ProgressBar.h"


Loader::Loader(int files) {
    this->files=files;
}

void Loader::transferAllFiles() {
    int max=this->getFiles();
    wxFrame* frame=new wxFrame(NULL,-1,wxString("Carica File"));
    //this->SetTopWindow(frame);
    frame->Show(true);
    dialog=new ProgressBar(wxString("Progress Bar"),wxString("Loading..."),max,frame,wxPD_AUTO_HIDE | wxPD_APP_MODAL|wxPD_REMAINING_TIME,this);
    for(int i=0;i<max;i++) {
        wxMilliSleep(5);
        notify(i);
    }
}

int Loader::getFiles() {
    return files;
}

Loader::Loader():Loader(0) {

}

void Loader::notify(int i) {
    dialog->update(i);
}
