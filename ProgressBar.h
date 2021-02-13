//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#   include <wx/wx.h>
#endif
#include "ManagerFile.h"
#include "Observer.h"
#include "LoaderWxApp.h"
#include "Subject.h"


class ProgressBar :public wxGauge, public Observer {
private:
    ManagerFile *managerFile;
public:
    ProgressBar(ManagerFile* managerFile,
                wxWindow *parent,
                wxWindowID id,
                int range,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxGA_HORIZONTAL
                );
    void update() override;
    void setRange(int r);
    void setValue(int value);
    virtual ~ProgressBar();
};


#endif //PROGRESSBAR_PROGRESSBAR_H
