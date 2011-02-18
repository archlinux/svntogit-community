/var/log/murmur/murmur.log {
	missingok
	postrotate
        /bin/kill -HUP `cat /var/run/murmur/murmur.pid 2>/dev/null` 2> /dev/null || true
	endscript
}
