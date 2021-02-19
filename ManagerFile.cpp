//
// Created by Francesco Villi on 30/08/2020.
//
#include "ManagerFile.h"
#include "ProgressBar.h"
#include <cstdio>
#include <iostream>


ManagerFile::ManagerFile(wxWindow *parent, const wxString &message, long style)
                                        :wxFileDialog(parent,message,"","","",style) {

}

void ManagerFile::LoadFile() {
    loadpath=0;
    for(int i=0;i<paths.GetCount();i++) {
        FILE *pfile = fopen(paths[i], "r");
        wxSleep(1);
        fclose(pfile);
        if(pfile==nullptr)
            throw std::invalid_argument("file non trovato");
        loadpath++;
        notify();
    }
    wxSleep(1);
    paths.clear();
}

wxArrayString ManagerFile::getAllPaths() {
    GetPaths(paths);
    return paths;
}


void ManagerFile::notify() {
    for(auto item:observers) {
        item->update();
    }
}

void ManagerFile::detach(Observer *obs) {
    if(obs!=nullptr)
        observers.remove(obs);
}

void ManagerFile::attach(Observer *obs) {
    if(obs!= nullptr)
        observers.push_back(obs);
}

ManagerFile::~ManagerFile() = default;

void ManagerFile::addPath(const wxString& path) {
    paths.push_back(path);
}

std::list<Observer *> ManagerFile::getObservers() {
    return observers;
}

void ManagerFile::clearRangeProgressBar() {
    for(auto item:observers)
        if(auto pb=dynamic_cast<ProgressBar*>(item))
            pb->setRange(this->getAllPaths().GetCount());
}

void ManagerFile::setValueProgressBar(int value) {
    for(auto item:observers)
        if(auto pb=dynamic_cast<ProgressBar*>(item))
            pb->setValue(value);
}

int ManagerFile::getLoadPaths() const {
    return loadpath;
}
