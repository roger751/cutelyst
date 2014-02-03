#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

#include <Cutelyst/Application>

#include "root.h"
#include "users.h"

#include <Cutelyst/Plugin/staticsimple.h>
#include <Cutelyst/Plugin/session.h>

using namespace std;

void registerPlugins(Context *ctx)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Cecilet Ti");
    QCoreApplication::setOrganizationDomain("ceciletti.com.br");
    QCoreApplication::setApplicationName("CuteWeb");
    QCoreApplication::setApplicationVersion("0.0.1");

    QCoreApplication app(argc, argv);
    Application *server = new Application;
    server->registerController(new Root);
    server->registerController(new Users);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QCoreApplication::installTranslator(&qtTranslator);

    QObject::connect(server, &Application::registerPlugins,
                [=](Context *ctx) {
        ctx->registerPlugin(new Plugin::StaticSimple(server));
        ctx->registerPlugin(new Plugin::Session(server));
    });

    if (server->parseArgs() && server->setup()) {
        return app.exec();
    }
    return server->printError();
}
