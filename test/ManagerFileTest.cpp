//
// Created by Francesco Villi on 12/02/2021.
//
#include "gtest/gtest.h"
#include "../ManagerFile.h"

TEST(ManagerFileTest,TestLetturaFileErrato){
    auto mf=new ManagerFile(nullptr);
    mf->addPath(R"(.\test\files\fileNotFound.txt)");
    EXPECT_THROW(mf->LoadFile(),std::invalid_argument);
}