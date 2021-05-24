#include <iostream>
#include"RepoT.h"
#include"TonomatCafea.h"
#include "TestsRepoR.h"
#include"TonomatCafea.h"
#include "UI.h"
#include "ServiceTonomat.h"
using namespace std;
int main() {
    RepoSTLTemplate<TonomatCafea> repoT;
    ServiceTonomat service(repoT);


    UI ui(service);
    ui.runMenu();
}
