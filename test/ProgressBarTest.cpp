//
// Created by Francesco Villi on 12/02/2021.
//
#include "gtest/gtest.h"
#include "../ProgressBar.h"
#include "../LoaderWxMain.h"
#include <memory>
TEST(ProgressBar, TestAttachAndDetach) {
    auto *mf=new ManagerFile(nullptr);
    auto *frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto *panel=new wxPanel(frame,-1);
    auto *pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    auto *observers_list=mf->getObservers();
    EXPECT_EQ(observers_list->size(),1);
    mf->detach(pb);
    EXPECT_EQ(observers_list->size(),0);
}
TEST(ProgressBar, TestAvanzamentoFileCorretti){
    auto *mf=new ManagerFile(nullptr);
    auto *frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto *panel=new wxPanel(frame,-1);
    auto *pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file1.txt)");
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file2.txt)");
    mf->LoadFile();
    auto value=pb->GetValue();
    EXPECT_EQ(value,2);
}

TEST(ProgressBar,TestNonAvanzamentoFileSbagliato){
    auto *mf=new ManagerFile(nullptr);
    auto *frame=new LoaderWxMain(NULL,"Application wxWidgets");
    auto *panel=new wxPanel(frame,-1);
    auto *pb=new ProgressBar(mf,panel,wxID_ANY,1,wxDefaultPosition,wxSize(500,25),wxGA_HORIZONTAL);
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\fileNotFound.txt)");
    try {
        mf->LoadFile();
    }catch(std::invalid_argument &e){}
    auto value=pb->GetValue();
    EXPECT_EQ(value,0);
}