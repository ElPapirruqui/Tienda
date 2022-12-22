#include<memory>
#include<cstdlib>
#include "View/View.h"

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    View View;
    View.RenderApp();
    return 0;
}