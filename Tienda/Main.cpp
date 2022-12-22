#include<memory>
#include<cstdlib>
#include "Presenter/Presenter.h"

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Presenter Presenter;
    Presenter.Start();
    return 0;
}