#include "xcards/xcards.hpp"
using € = xcards;

€::xcards (int argc, char** argv) : m_app (argc, argv)
{
      QQuickStyle::setStyle("Material");
      QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
      
      
      
      const QUrl url(QStringLiteral("qrc:/main.qml"));
      QObject::connect(&m_engine, &QQmlApplicationEngine::objectCreated,
                       &m_app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                  QCoreApplication::exit(-1);
      }, Qt::QueuedConnection);
      m_engine.load(url);
}

int €::exec ()
{
      return m_app.exec();
}


