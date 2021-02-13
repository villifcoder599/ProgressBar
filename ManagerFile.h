//
// Created by Francesco Villi on 30/08/2020.
//

#ifndef PROGRESSBAR_MANAGERFILE_H
#define PROGRESSBAR_MANAGERFILE_H
#include <filesystem>
#include "Subject.h"
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

class ManagerFile: public wxFileDialog, public Subject {
public:
    ManagerFile(wxWindow *parent,
                const wxString& message = wxASCII_STR(wxFileSelectorPromptStr),
                long style = wxFD_DEFAULT_STYLE);
    void LoadFile();
    wxArrayString getAllPaths();
    int getLoadPaths();
    void addPath(const wxString path);
    void attach(Observer *obs) override;
    void detach(Observer *obs) override;
    void notify() override;
    void setRangeProgressBar();
    void setValueProgressBar(int value);
    std::list<Observer*> *getObservers();
    virtual ~ManagerFile();

private:
    wxArrayString paths;
    int loadPaths=0;
    int errori=0;
};


#endif //PROGRESSBAR_MANAGERFILE_H
