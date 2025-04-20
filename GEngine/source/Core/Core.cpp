module;

#include "Log.h"

module Core;

int main(int argc, char* argv[])
{
    GEngine::Log::Init();
    auto app = GEngine::CreateApplication();
    delete app;
}
