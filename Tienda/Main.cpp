#include<iostream>
#include<memory>
#include<string>
#include<cstdlib>
#include "View/View.h"

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    View View;
    View.RenderApp();
    cout << "exit";
    return 0;
}