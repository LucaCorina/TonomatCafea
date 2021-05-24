#pragma once
#include "RepoT.h"
#include "TonomatCafea.h"
#include <cassert>
using namespace std;
void TestRepo(RepoSTLTemplate<TonomatCafea>& repotest){
    string nume="yy",nume1="dap";
    TonomatCafea e1(1,67,nume);
    TonomatCafea e2(2,67,nume1);
    TonomatCafea e3(3,67,nume);
    TonomatCafea e4(4,67,nume1);


    repotest.addElem(e1);
    repotest.addElem(e2);
    repotest.addElem(e3);
    repotest.addElem(e4);
    assert(repotest.getAll()[0]==e1);
    assert(repotest.getAll()[1]==e2);
    assert(repotest.getAll()[2]==e3);
    assert(repotest.getAll()[3]==e4);


   repotest.deleteElem(2);
   repotest.addElem(e3);
   assert(repotest.getAll()[3]==e3);





}