//
// Created by Francesco Villi on 29/08/2020.
//

#ifndef PROGRESSBAR_LOADERWXMAIN_H
#define PROGRESSBAR_LOADERWXMAIN_H
#include "LoaderWxApp.h"

class LoaderWxMain: public wxFrame {
public:
    LoaderWxMain(wxFrame* frame,const wxString &title);
    ~LoaderWxMain();
private:
    wxBoxSizer *m_MainBox;
    wxButton* m_Button_ChooseFiles;
    wxButton* m_Button_LoadFiles;
    wxPanel *panel;
    wxStaticText *m_Label_Button_ChooseFiles;
    const wxColour *m_background_color;
    wxArrayString paths;
    wxGauge *progressBar;
    wxListBox *listBox;
    wxTextCtrl *label_path;

    void onClickChooseFiles(wxCommandEvent &event);
    void onClose(wxCloseEvent &event);
    void onQuit(wxCommandEvent &event);
    void onClickLoad(wxCommandEvent &event);
    void onAbout(wxCommandEvent &event);

public:
    const wxArrayString &getPaths() const;
    wxListBox *getListBox() const;
    void setPaths(const wxArrayString &paths);

DECLARE_EVENT_TABLE();
    enum{
        idButtonLoad=8,
        idButtonChoose=9,
        idMenuQuit=10,
        idMenuAbout=11,
    };
};


#endif //PROGRESSBAR_LOADERWXMAIN_H