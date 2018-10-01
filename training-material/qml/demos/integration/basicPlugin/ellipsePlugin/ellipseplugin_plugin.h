#ifndef ELLIPSEPLUGIN_PLUGIN_H
#define ELLIPSEPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class EllipsePluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // ELLIPSEPLUGIN_PLUGIN_H
