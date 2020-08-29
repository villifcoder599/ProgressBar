//
// Created by Francesco Villi on 15/07/2020.
//

#ifndef PROGRESSBAR_LOADERWXAPP_H
#define PROGRESSBAR_LOADERWXAPP_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

class LoaderWxApp: public wxApp {
public:
    virtual bool OnInit();
};



#endif //PROGRESSBAR_LOADERWXAPP_H
