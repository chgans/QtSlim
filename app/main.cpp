#include "slimapplication.h"

int main(int argc, char *argv[])
{
    SlimApplication app(argc, argv);
    app.setOrganizationName("Ch'Gans Engineering Ltd.");
    app.setOrganizationDomain("chgans.engineering");
    app.setApplicationName("QtSlim");
    return app.exec();
}
