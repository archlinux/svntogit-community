/var/log/thttpd/*log {
	missingok
	postrotate
	systemctl status thttpd.service | grep -q running &&
	systemctl restart thttpd.service >/dev/null 
	endscript
}
