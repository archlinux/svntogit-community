#!/bin/sh
export STEAM_RUNTIME=0
# Workaround for dbus fatal termination related coredumps (SIGABRT)
# https://github.com/ValveSoftware/steam-for-linux/issues/4464
export DBUS_FATAL_WARNINGS=0
exec /usr/bin/steam "$@"
