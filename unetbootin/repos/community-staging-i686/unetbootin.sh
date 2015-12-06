#!/bin/sh
# See FS#42030 for more information about the QT_X11_NO_MITSHM=1 workaround
QT_X11_NO_MITSHM=1 /usr/bin/unetbootin.elf "$@"
