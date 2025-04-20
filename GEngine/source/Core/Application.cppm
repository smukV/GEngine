export module Core.Application;

namespace GEngine {
    export class Application
    {
    public:
        Application();
        virtual ~Application();
    };

    export Application* CreateApplication();
};
