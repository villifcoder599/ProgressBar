//
// Created by Francesco Villi on 29/08/2020.
//
#include "LoaderWxMain.h"

BEGIN_EVENT_TABLE(LoaderWxMain,wxFrame)
                EVT_CLOSE(LoaderWxMain::onClose)
                EVT_MENU(idMenuQuit, LoaderWxMain::onQuit)
                EVT_MENU(idMenuAbout, LoaderWxMain::onAbout)
                EVT_BUTTON(idButtonChoose, LoaderWxMain::onClickChooseFiles)
                EVT_BUTTON(idButtonLoad,LoaderWxMain::onClickLoad)

END_EVENT_TABLE()

LoaderWxMain::LoaderWxMain(wxFrame *frame, const wxString &title):wxFrame(frame,-1,title) {
    auto *menubar=new wxMenuBar();
    auto *menu=new wxMenu("");
    auto *hbox_pathFile=new wxBoxSizer(wxHORIZONTAL);
    auto *hbox_listBox=new wxBoxSizer(wxHORIZONTAL);
    auto *hbox_progress=new wxBoxSizer(wxHORIZONTAL);
    auto *hbox_Buttons=new wxBoxSizer(wxHORIZONTAL);
    auto *helpMenu=new wxMenu();
    panel=new wxPanel(this,-1);
    m_MainBox=new wxBoxSizer(wxVERTICAL);
    m_Button_ChooseFiles=new wxButton(panel, idButtonChoose, "Choose files", wxDefaultPosition, wxDefaultSize, 0);
    m_Button_LoadFiles=new wxButton(panel,idButtonLoad,"Load Files", wxDefaultPosition, wxDefaultSize, 0);
    m_Label_Button_ChooseFiles=new wxStaticText(panel,wxID_ANY,"Path Info");
    label_path=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxDefaultSize,wxTE_READONLY);
    m_background_color=new wxColour(255,255,255);
    listBox=new wxListBox(panel,wxID_ANY,wxDefaultPosition,wxDefaultSize,0,NULL,wxLB_NEEDED_SB);
    dirDialog=new ManagerFile(this,"Select files",wxFD_DEFAULT_STYLE|wxFD_MULTIPLE);
    progressBar=new ProgressBar(dirDialog,panel,wxID_ANY,0,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);

    m_MainBox->Add(hbox_pathFile, 0, wxALL | wxGROW, 10);
    m_MainBox->Add(hbox_listBox, 1, wxALL | wxGROW, 10);
    m_MainBox->Add(-1,5);
    m_MainBox->Add(hbox_progress,0,wxRIGHT|wxLEFT|wxGROW,10);
    m_MainBox->Add(-1,5);
    m_MainBox->Add(hbox_Buttons,0,wxALL,10);
    hbox_Buttons->Add(m_Button_ChooseFiles,0,wxRIGHT,10);
    hbox_Buttons->Add(m_Button_LoadFiles);
    hbox_progress->Add(progressBar,1,wxGROW);
    hbox_listBox->Add(listBox, 1, wxALL|wxGROW );
    hbox_pathFile->Add(m_Label_Button_ChooseFiles, 0, wxCENTER);
    hbox_pathFile->Add(10, -1, 0, wxRIGHT | wxLEFT);
    hbox_pathFile->Add(label_path, 1);
    label_path->SetCursor(*wxSTANDARD_CURSOR);
    menu->Append(idMenuQuit,("&Quit\tAlt-F4"),("Quit the app"));
    helpMenu->Append(idMenuAbout,("&About\tF1"),("Show info about this app"));
    menubar->Append(menu,"&File");
    menubar->Append(helpMenu,"&Help");
    panel->SetSizer(m_MainBox);
    this->SetSizeHints(wxDefaultSize,wxDefaultSize);
    this->CreateStatusBar(2);
    this->SetBackgroundColour(*m_background_color);
    this->SetMenuBar(menubar);
    this->SetStatusText("Status bar");
}
LoaderWxMain::~LoaderWxMain()= default;

void LoaderWxMain::onClose(wxCloseEvent &event){
    Destroy();
}

void LoaderWxMain::onQuit(wxCommandEvent &event){
    Destroy();
}

void LoaderWxMain::onAbout(wxCommandEvent &event)
{
    wxMessageBox(("Simulazione caricamento file"));
}


void LoaderWxMain::onClickChooseFiles(wxCommandEvent &event) {
    listBox->Clear();
    if(dirDialog->ShowModal()==wxID_OK){
        label_path->SetLabel((dirDialog->getAllPaths())[0].substr(0,(dirDialog->getAllPaths())[0].find_last_of("\\")+1));
        if(!((dirDialog->getAllPaths()).IsEmpty())) {
            for(auto item:dirDialog->getAllPaths()){
                listBox->Append(item.substr(item.find_last_of("\\")+1));
            }

        }
    }
}

void LoaderWxMain::onClickLoad(wxCommandEvent &event) {
    if(!listBox->IsEmpty()) {
        dirDialog->setRangeProgressBar();
        dirDialog->LoadFile();

        dirDialog->setValueProgressBar(0);
        listBox->Clear();
        label_path->Clear();
    }
    else{
        wxMessageBox("Devi prima scegliere i file!","Alert");
    }
}
