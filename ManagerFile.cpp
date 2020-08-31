//
// Created by Francesco Villi on 30/08/2020.
//

#include "ManagerFile.h"
#include "ProgressBar.h"

ManagerFile::ManagerFile(wxWindow *parent, const wxString &message, long style):wxFileDialog(parent,message,"","","",style) {

}

void ManagerFile::LoadFile() {
    this->GetPaths(paths);
    int count=paths.GetCount();
    for(auto item:observers) {
        if (auto *app = dynamic_cast<ProgressBar *>(item)) {
            app->SetRange(count);
            count = 0;
            for (auto elem:paths) {
                //..loading...
                wxSleep(1);
                count++;
                notify(count);
            }
            wxMessageBox(("Complete!"),"Message");
            app->SetRange(0);
            delete app;
        }
    }

}

wxArrayString ManagerFile::getPaths() {
    this->GetPaths(paths);
    return paths;
}

ManagerFile::~ManagerFile() {

}

void ManagerFile::notify(int i) {
    for(auto item:observers)
        item->update(i);
}

void ManagerFile::detach(Observer *obs) {
    if(obs!=nullptr)
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ManagerFile::attach(Observer *obs) {
    if(obs!= nullptr)
        observers.push_back(obs);
}