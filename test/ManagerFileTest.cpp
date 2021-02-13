//
// Created by Francesco Villi on 12/02/2021.
//
#include "gtest/gtest.h"
#include "../ManagerFile.h"


TEST(ManagerFileTest, TestLetturaFileCorretti) {
    auto *mf=new ManagerFile(nullptr);
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file1.txt)");
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file2.txt)");
    mf->LoadFile();
    ASSERT_EQ(2,mf->getLoadPaths());
}

TEST(ManagerFileTest,TestLetturaFileErrato){
    auto *mf=new ManagerFile(nullptr);
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\fileNotFound.txt)");
    try{
        mf->LoadFile();
    }catch(std::invalid_argument &e){
        EXPECT_STREQ("file non trovato",e.what());
    }

}

TEST(ManagerFileTest,TestLetturaPiuDocumenti){
    auto *mf=new ManagerFile(nullptr);
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file1.txt)");
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file2.txt)");
    mf->LoadFile();
    ASSERT_EQ(2,mf->getLoadPaths());
    mf->addPath(R"(C:\Users\Francesco Villi\CLionProjects\ProgressBar\test\files\file3.txt)");
    mf->LoadFile();
    ASSERT_EQ(1,mf->getLoadPaths());
}
