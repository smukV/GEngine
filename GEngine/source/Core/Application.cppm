export module Core.Application;

import <string>;

namespace GEngine {
    export class Application
    {
    public:
        Application(std::string appName = "Untitled");
        virtual ~Application();

        std::string GetName() { return m_Name; }

    private:
        std::string m_Name;
    };

    export Application* CreateApplication();
};
