#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/vbox/vbox.cfg

MODLIST=()
LOG="/var/log/vbox-install.log"

if [ -n "$INSTALL_DIR" ]; then
  VBOXMANAGE="$INSTALL_DIR/VBoxManage"
  BUILDVBOXDRV="$INSTALL_DIR/src/vboxdrv/build_in_tmp"
  BUILDVBOXNETFLT="$INSTALL_DIR/src/vboxnetflt/build_in_tmp"
  BUILDVBOXNETADP="$INSTALL_DIR/src/vboxnetadp/build_in_tmp"
  BUILDVBOXPCI="$INSTALL_DIR/src/vboxpci/build_in_tmp"
else
  echo "missing vbox.cfg"
  exit 0
fi

case "$1" in
  setup)
    stat_busy "Unloading VirtualBox kernel modules"
    for module in vbox{netflt,netadp,drv}; do
      if grep -q "^${module}" /proc/modules; then
        MODLIST+=($module)
        modprobe -r $module
      fi
    done
    stat_done
    for p in /lib/modules/*; do
      if [ ! -d "$p/kernel" ]; then
        if [ -e "$p/misc/vboxdrv.ko" ]; then
          stat_busy "Removing old VirtualBox kernel modules from $p"
          rm -f "$p/misc/vbox"{drv,netadp,netflt,pci}.ko 2>/dev/null
          rmdir -p --ignore-fail-on-non-empty "$p/misc/" 2>/dev/null
          stat_done
        fi
      fi
    done
    if find /lib/modules/`uname -r` -name "vboxnetadp\.*" 2>/dev/null|grep -q vboxnetadp; then
      stat_busy "Removing old VirtualBox netadp kernel module"
      find /lib/modules/`uname -r` -name "vboxnetadp\.*" 2>/dev/null|xargs rm -f 2>/dev/null
      stat_done
    fi
    if find /lib/modules/`uname -r` -name "vboxnetflt\.*" 2>/dev/null|grep -q vboxnetflt; then
      stat_busy "Removing old VirtualBox netflt kernel module"
      find /lib/modules/`uname -r` -name "vboxnetflt\.*" 2>/dev/null|xargs rm -f 2>/dev/null
      stat_done
    fi
    if find /lib/modules/`uname -r` -name "vboxdrv\.*" 2>/dev/null|grep -q vboxdrv; then
      stat_busy "Removing old VirtualBox kernel module"
      find /lib/modules/`uname -r` -name "vboxdrv\.*" 2>/dev/null|xargs rm -f 2>/dev/null
      stat_done
    fi
    if find /lib/modules/`uname -r` -name "vboxpci\.*" 2>/dev/null|grep -q vboxpci; then
      stat_busy "Removing old VirtualBox pci kernel module"
      find /lib/modules/`uname -r` -name "vboxpci\.*" 2>/dev/null|xargs rm -f 2>/dev/null
      stat_done
    fi

    stat_busy "Recompiling VirtualBox kernel modules"
    if ! $BUILDVBOXDRV \
      --save-module-symvers /tmp/vboxdrv-Module.symvers \
      --no-print-directory install > $LOG 2>&1; then
      echo  "Look at $LOG to find out what went wrong"
    fi
    if ! $BUILDVBOXNETFLT \
      --use-module-symvers /tmp/vboxdrv-Module.symvers \
      --no-print-directory install >> $LOG 2>&1; then
      echo "Look at $LOG to find out what went wrong"
    fi
    if ! $BUILDVBOXNETADP \
      --use-module-symvers /tmp/vboxdrv-Module.symvers \
      --no-print-directory install >> $LOG 2>&1; then
      echo "Look at $LOG to find out what went wrong"
    fi
    if ! $BUILDVBOXPCI \
      --use-module-symvers /tmp/vboxdrv-Module.symvers \
      --no-print-directory install >> $LOG 2>&1; then
      echo "Look at $LOG to find out what went wrong"
    fi
    stat_done
    stat_busy "Reloading VirtualBox kernel modules"
    for module in "${MODLIST[@]}"; do
      modprobe $module
    done
    stat_done
    ;;
  *)
    echo "usage: $0 {setup}"
esac
