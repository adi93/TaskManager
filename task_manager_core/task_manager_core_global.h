#ifndef TASK_MANAGER_CORE_GLOBAL_H
#define TASK_MANAGER_CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TASK_MANAGER_CORE_LIBRARY)
#  define TASK_MANAGER_CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define TASK_MANAGER_CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TASK_MANAGER_CORE_GLOBAL_H
