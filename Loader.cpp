//
// Created by Francesco Villi on 15/07/2020.
//

#include <unistd.h>
#include <cstdlib>
#include "ProgressBar.h"
wxIMPLEMENT_APP(Loader);

Loader::Loader(int files) {
    this->files=files;
}

bool Loader::OnInit() {
    int max=this->getFiles();
    wxFrame* frame=new wxFrame(NULL,-1,wxString("Carica File"));
    frame->Show(true);
    dialog=new ProgressBar(wxString("Progress Bar"),wxString("Loading..."),max,frame,wxPD_AUTO_HIDE | wxPD_APP_MODAL|wxPD_REMAINING_TIME);
    for(int i=0;i<max;i++) {
        wxMilliSleep(25);
        notify(i);
    }
    dialog->update(max);
    delete dialog;
    return true;
}

int Loader::getFiles() {
    return files;
}

void Loader::attach(Observer *obs) {
    observers.push_front(obs);
}
void Loader::detach(Observer *obs) {
    observers.remove(obs);
}
void Loader::notify(int i) {
    dialog->update(i);
}