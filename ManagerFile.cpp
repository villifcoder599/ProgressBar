//
// Created by Francesco Villi on 30/08/2020.
//
#include "ManagerFile.h"
#include "ProgressBar.h"
#include <stdio.h>
#include <iostream>
ManagerFile::ManagerFile(wxWindow *parent, const wxString &message, long style):wxFileDialog(parent,message,"","","",style) {

}

void ManagerFile::LoadFile() {
    addPath("cartella/test.txt");
    std::cout << paths.GetCount();
    int errori=0;
    for(int i=0;i<paths.GetCount();i++) {
        try {
            FILE *pfile = fopen(paths[i], "r");
            wxSleep(1);
            if(pfile==nullptr) {
                errori++;
                throw std::exception();
            }
        } catch (std::exception& e) { }
        loadPaths++;
        notify();
    }
    if(errori>0)
        wxMessageBox("Sono stati trovati "+ std::to_string(errori) + " file non validi","alert");
}

wxArrayString ManagerFile::getAllPaths() {
    GetPaths(paths);
    return this->paths;
}


void ManagerFile::notify() {
    for(auto item:observers)
        item->update();
}

void ManagerFile::detach(Observer *obs) {
    if(obs!=nullptr)
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ManagerFile::attach(Observer *obs) {
    if(obs!= nullptr)
        observers.push_back(obs);
}

ManagerFile::~ManagerFile() {

}

void ManagerFile::addPath(const wxString path) {
    paths.Insert(path,0);
}

int ManagerFile::getLoadPaths() {
    return loadPaths;
}
