//
// Created by Francesco Villi on 15/07/2020.
//

#include <dirent.h>
#include "ProgressBar.h"
#include "Loader.h"
#ifdef _WIN32
#include <windows.h>
#include <wx/msgdlg.h>
void sleep(unsigned milliseconds)
{
    Sleep(milliseconds);
}
#else
#include <unistd.h>
    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif
wxIMPLEMENT_APP(Loader);

Loader::Loader(std::string path) {
    this->path=path;
}
Loader::Loader():Loader::Loader(""){}

int Loader::getNumFiles() {
    int count=0;
    if((dir = opendir(path.c_str()))!=NULL)
        while((ent=readdir(dir))!=NULL) {
            if (ent->d_name[0] != '.') {
                count++;
            }
        }
    else
        wxMessageBox("No such file or directory");
    return count;
}

bool Loader::OnInit() {
    this->path="../files";
    int max=this->getNumFiles();
    if(max>0) {
        wxFrame *frame = new wxFrame(NULL, -1, wxString("Load Files"));
        frame->Show(true);
        dialog = new ProgressBar(wxString("Progress Bar"), wxString("Loading..."), max, frame,
                                 wxPD_AUTO_HIDE | wxPD_APP_MODAL);
        LoadFiles();
        wxMessageBox("All files have been read!","Notify");
        delete dialog;
    }
    return true;
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

void Loader::LoadFiles() {
    if((dir = opendir(path.c_str()))!=NULL) {
        int count=0;
        while ((ent = readdir(dir)) != NULL)
            if (ent->d_name[0] != '.') {
                sleep(350);
                notify(++count);
            }
    }
    else
        wxMessageBox("No such file or directory","Error");
}
