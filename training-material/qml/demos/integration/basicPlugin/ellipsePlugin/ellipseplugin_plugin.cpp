#include "ellipseplugin_plugin.h"
#include "ellipseitem.h"

#include <qqml.h>

void EllipsePluginPlugin::registerTypes(const char *uri)
{
    // @uri Shapes
    qmlRegisterType<EllipseItem>(uri, 9, 0, "Ellipse");
}

