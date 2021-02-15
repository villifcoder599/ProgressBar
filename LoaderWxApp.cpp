//
// Created by Francesco Villi on 15/07/2020.
//

#include "LoaderWxApp.h"
#include <windows.h>
#include "LoaderWxMain.h"
wxIMPLEMENT_APP(LoaderWxApp);


bool LoaderWxApp::OnInit() {
    auto *frame=new LoaderWxMain(NULL,"Application wxWidgets");
    frame->SetMinSize(wxSize(350,350));
    frame->SetMaxSize(wxSize(700,800));
    frame->Show();
    return true;
}
