#!/bin/sh -e
# Replacement for upstream mount helper using udisks/eject
# (C) 2010 Martin Pitt <mpitt@debian.org>

ACTION="$1"
DEV="$2"

case "$ACTION" in
    mount)
	udisks --mount "$DEV"
    
	# check if mount worked. If not, fail
	# udisks does return 0 even if mount failed
	mount | grep -q "$DEV" || exit 0
	;;

    eject)
	eject "$DEV"
	;;

    cleanup)
	;;

    *)
	echo "unknown action" >&2
	exit 1
esac

