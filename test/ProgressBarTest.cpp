//
// Created by Francesco Villi on 12/02/2021.
//
#include "gtest/gtest.h"
#include "../ProgressBar.h"
#include "../LoaderWxMain.h"
#include <memory>
TEST(ProgressBar, TestAttach) {
    auto mf=new ManagerFile(nullptr);
    auto frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto panel=new wxPanel(frame,-1);
    auto pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    auto observers_list=mf->getObservers();
    EXPECT_EQ(observers_list.size(),1);
}
TEST(ProgressBar,TestDetach){
    auto mf=new ManagerFile(nullptr);
    auto frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto panel=new wxPanel(frame,-1);
    auto pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    mf->detach(pb);
    auto observers_list=mf->getObservers();
    observers_list=mf->getObservers();
    EXPECT_EQ(observers_list.size(),0);
}
TEST(ProgressBar, TestAvanzamentoFileCorretti){
    auto mf=new ManagerFile(nullptr);
    auto frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto panel=new wxPanel(frame,-1);
    auto pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    mf->addPath(R"(.\test\files\file1.txt)");
    mf->addPath(R"(.\test\files\file2.txt)");
    mf->LoadFile();
    auto value=pb->GetValue();
    EXPECT_EQ(value,2);
}
//aggiungi test con file errato in ingresso
TEST(ProgressBar,TestAvanzamentoFileErrato){
    auto mf=new ManagerFile(nullptr);
    auto frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto panel=new wxPanel(frame,-1);
    auto pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    mf->addPath(R"(.\test\files\file1.txt)");
    mf->addPath(R"(.\test\files\not_exist.txt)");
    try {
        mf->LoadFile();
    }catch(std::invalid_argument &e){}
    auto value=pb->GetValue();
    EXPECT_EQ(value,1);
    delete mf;
}
