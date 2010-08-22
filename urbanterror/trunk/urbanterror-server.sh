#!/bin/sh
# cleanup mess, i did in last release
if [ -d ~/.urbanterror/baseut4 ]; then
	mkdir -p ~/.urbanterror/q3ut4
	mv ~/.urbanterror/baseut4/*  ~/.urbanterror/q3ut4/
	rmdir ~/.urbanterror/baseut4
fi
# start server
cd /opt/urbanterror/
exec ./ioUrTded "$@"

