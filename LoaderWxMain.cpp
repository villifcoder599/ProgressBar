//
// Created by Francesco Villi on 29/08/2020.
//

#include "LoaderWxMain.h"
enum wxbuildinfoformat {
    short_f, long_f };
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(LoaderWxMain,wxFrame)
                EVT_CLOSE(LoaderWxMain::onClose)
                EVT_MENU(idMenuQuit, LoaderWxMain::onQuit)
                EVT_MENU(idMenuAbout, LoaderWxMain::onAbout)
                EVT_BUTTON(idButtonChoose, LoaderWxMain::onClickChooseFiles)
                EVT_BUTTON(idButtonLoad,LoaderWxMain::onClickLoad)

END_EVENT_TABLE()

LoaderWxMain::LoaderWxMain(wxFrame *frame, const wxString &title):wxFrame(frame,-1,title) {
    wxMenuBar* menubar=new wxMenuBar();
    wxMenu *menu=new wxMenu("");
    panel=new wxPanel(this,-1);
    m_MainBox=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox_pathFile=new wxBoxSizer(wxHORIZONTAL);
    m_Button_ChooseFiles=new wxButton(panel, idButtonChoose, "Choose files", wxDefaultPosition, wxDefaultSize, 0);
    m_Button_LoadFiles=new wxButton(panel,idButtonLoad,"Load Files", wxDefaultPosition, wxDefaultSize, 0);
    m_Label_Button_ChooseFiles=new wxStaticText(panel,wxID_ANY,"Path Info");
    label_path=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxDefaultSize,wxTE_READONLY);
    wxMenu *helpMenu=new wxMenu();
    m_background_color=new wxColour(255,255,255);
    wxBoxSizer *hbox_listBox=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox_progress=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox_Buttons=new wxBoxSizer(wxHORIZONTAL);
    listBox=new wxListBox(panel,wxID_ANY,wxDefaultPosition,wxDefaultSize,0,NULL,wxLB_NEEDED_SB);
    progressBar=new wxGauge(panel,wxID_ANY,0,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    m_MainBox->Add(hbox_pathFile, 0, wxALL | wxGROW, 10);
    m_MainBox->Add(hbox_listBox, 1, wxALL | wxGROW, 10);
    m_MainBox->Add(-1,5);
    m_MainBox->Add(hbox_progress,0,wxRIGHT|wxLEFT|wxGROW,10);
    m_MainBox->Add(-1,5);
    m_MainBox->Add(hbox_Buttons,0,wxALL,10);
    hbox_Buttons->Add(m_Button_ChooseFiles,0,wxRIGHT,10);
    hbox_Buttons->Add(m_Button_LoadFiles);
    hbox_progress->Add(progressBar,1,wxGROW);
    label_path->SetCursor(*wxSTANDARD_CURSOR);
    menu->Append(idMenuQuit,("&Quit\tAlt-F4"),("Quit the app"));
    helpMenu->Append(idMenuAbout,("&About\tF1"),("Show info about this app"));
    menubar->Append(menu,"&File");
    menubar->Append(helpMenu,"&Help");
    hbox_pathFile->Add(m_Label_Button_ChooseFiles, 0, wxCENTER);
    hbox_pathFile->Add(10, -1, 0, wxRIGHT | wxLEFT);
    hbox_pathFile->Add(label_path, 1);
    hbox_listBox->Add(listBox, 1, wxALL|wxGROW );
    this->SetSizeHints(wxDefaultSize,wxDefaultSize);
    SetBackgroundColour(*m_background_color);
    panel->SetSizer(m_MainBox);
    SetMenuBar(menubar);
    CreateStatusBar(2);
    SetStatusText("Status bar");
    SetStatusText(wxbuildinfo(short_f),1);
}
LoaderWxMain::~LoaderWxMain(){}

void LoaderWxMain::onClose(wxCloseEvent &event){
    Destroy();
}

void LoaderWxMain::onQuit(wxCommandEvent &event){
    Destroy();
}

void LoaderWxMain::onAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void LoaderWxMain::onClickChooseFiles(wxCommandEvent &event) {
    paths.Clear();
    listBox->Clear();
    wxFileDialog *dirDialog=new wxFileDialog(this,"Choose your files","","","",wxFD_DEFAULT_STYLE|wxFD_MULTIPLE);
    if(dirDialog->ShowModal()==wxID_OK){
        dirDialog->GetPaths(paths);
    }
    dirDialog->Destroy();
    label_path->SetLabel((paths)[0].substr(0,paths[0].find_last_of("\\")+1));
    if(!paths.IsEmpty()) {
        for(auto item:paths){
            listBox->Append(item.substr(item.find_last_of("\\")+1));
        }
    }
}

void LoaderWxMain::onClickLoad(wxCommandEvent &event) {
    progressBar->SetRange(paths.GetCount());
    int count=0;
    for(auto elem:paths){
        wxSleep(1);
        count++;
        progressBar->SetValue(count);
    }
    wxMessageBox(("Complete!"));
    progressBar->SetValue(0);
    listBox->Clear();
    label_path->Clear();
    paths.Clear();
}

void LoaderWxMain::setPaths(const wxArrayString &paths) {
    LoaderWxMain::paths = paths;
}
const wxArrayString &LoaderWxMain::getPaths() const {
    return paths;
}
wxListBox *LoaderWxMain::getListBox() const {
    return listBox;
}
