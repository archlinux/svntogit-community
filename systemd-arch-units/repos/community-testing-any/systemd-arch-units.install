#!/bin/sh

reload_units() {
  # reread all known unit files if systemd is running
  if [ -e sys/fs/cgroup/systemd ]; then
    kill -1 1
  fi
}

## arg 1:  the new package version
post_install() {
  cat << EOF
-- NOTICE -------------------------------------------------------------
All unit files have been installed to /lib/systemd/system. This only
allows systemd to be aware of them. It will not register them for
automatic activation on boot. Use 'systemctl enable <unit>' to ensure
that a unit is started at boot.
-----------------------------------------------------------------------
EOF

  reload_units
}

post_remove() {
  reload_units
}

post_upgrade() {
  reload_units
}

# vim:set ts=2 sw=2 et:
