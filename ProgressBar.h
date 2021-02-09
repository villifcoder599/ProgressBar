//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#include <wx/progdlg.h>
#include "Observer.h"
#include "LoaderWxApp.h"
#include "Subject.h"


#endif

class ProgressBar :public wxGauge, public Observer {
private:
    Subject *managerFile;
public:
    ProgressBar(wxWindow *parent,
                wxWindowID id,
                int range,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxGA_HORIZONTAL,
                Subject *managerFile= nullptr);
    void update(int value) override;

    ~ProgressBar();
};


#endif //PROGRESSBAR_PROGRESSBAR_H
