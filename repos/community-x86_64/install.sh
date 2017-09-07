post_install() {
    getent group  xmms2 > /dev/null || groupadd -r xmms2
    getent passwd xmms2 > /dev/null || useradd  -r -g xmms2 -d /var/lib/xmms2 -s /bin/false -G audio xmms2
    chown -R xmms2:xmms2 var/lib/xmms2
    true
}

post_upgrade() {
  post_install
}
