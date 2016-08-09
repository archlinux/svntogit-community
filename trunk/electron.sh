#!/usr/bin/bash

export GDK_BACKEND=x11

# Workaround for scaling issues on HiDPI displays
export GDK_SCALE=${GDK_SCALE:-1}

exec /usr/lib/electron/electron "$@"
