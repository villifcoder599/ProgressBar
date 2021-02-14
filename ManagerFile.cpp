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
    this->loadPaths=0;
    errori=0;
    for(int i=0;i<paths.GetCount();i++) {
        try {
            FILE *pfile = fopen(paths[i], "r");
            wxSleep(1);
            fclose(pfile);
            if(pfile==nullptr) {
                errori++;
                throw std::invalid_argument("file non trovato");
            }
            else
                loadPaths++;
        } catch (std::invalid_argument& e) { }
        notify();
    }
    wxSleep(1);
    this->paths.clear();
//    if(errori>0)
//        wxMessageBox("Sono stati trovati "+ std::to_string(errori) + " file non validi","alert");
}

wxArrayString ManagerFile::getAllPaths() {
    GetPaths(paths);
    return this->paths;
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

ManagerFile::~ManagerFile() {

}

void ManagerFile::addPath(const wxString path) {
    paths.push_back(path);
}

int ManagerFile::getLoadPaths() {
    return loadPaths;
}

std::list<Observer *> *ManagerFile::getObservers() {
    return &observers;
}

void ManagerFile::setRangeProgressBar() {
    for(auto item:observers)
        if(auto pb=dynamic_cast<ProgressBar*>(item))
            pb->setRange(this->getAllPaths().GetCount());
}

void ManagerFile::setValueProgressBar(int value) {
    for(auto item:observers)
        if(auto pb=dynamic_cast<ProgressBar*>(item))
            pb->setValue(value);
}
