TEMPLATE = subdirs

SUBDIRS += \
    task_manager_core \
    task_manager_desktop
task_manager_desktop.depends = task_manager_core
