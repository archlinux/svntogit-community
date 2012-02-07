/var/log/privoxy/* {
   create 660 root privoxy
   notifempty
   compress
   postrotate
     /bin/kill -HUP `cat /var/run/privoxy.pid 2>/dev/null` 2> /dev/null || true
   endscript
}
