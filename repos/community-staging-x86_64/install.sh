post_install() {
    getent group  xmms2 > /dev/null || groupadd -r -g 46 xmms2
    getent passwd xmms2 > /dev/null || useradd  -r -u 46 -g xmms2 -d /var/lib/xmms2 -s /bin/false -G audio xmms2
    usr/bin/systemd-tmpfiles --create xmms2.conf
    true
}

post_upgrade() {
  post_install
}