TEMPLATE = subdirs

SUBDIRS += \
    task_manager_core \
    task-manager-desktop
task-manager-desktop.depends = task_manager_core
