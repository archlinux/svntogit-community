#!/bin/sh

#
# Control script grant/revoke access to X for the ATI External Events Daemon
#
# Distro maintainers may modify this reference script as necessary to conform
# to their distribution policies.
#
# Copyright (c) 2006, ATI Technologies Inc.  All rights reserved.
#

#
# Parameters:
#   $1 is a keyword, either "grant" or "revoke"
#   $2 is the display name
#   $3 is the X authorization file to be authorized
#
# Returns:
#   0 if authorization was successfully granted/revoked
#   nonzero on failure
#
# Note:
#   The third parameter only makes sense if xauth is being used.  If another
#   mechanism such as xhost is being used it can be ignored.  For setups that
#   do not do any form of authentication(!) this script can be trimmed down
#   to just "exit 0" and the daemon will assume that it is always authorized.
#

GetServerAuthFile()
{
    # Determine where the authorization key may be hiding.  The location will
    # vary depending upon whether X was started via xdm/kdm, gdm or startx, so
    # check each one in turn.

    # Check xdm/kdm

    XDM_AUTH_MASK=/var/lib/xdm/authdir/authfiles/A$1*
    XDM_AUTH_FILE=`ls -t $XDM_AUTH_MASK 2>/dev/null | head -n 1`   # Choose the newest file
    if [ -n "$XDM_AUTH_FILE" ]; then
        SERVER_AUTH_FILE=$XDM_AUTH_FILE
        DISP_SEARCH_STRING="#ffff#"
        return 0
    fi

    # Check gdm

    GDM_AUTH_FILE=/var/lib/gdm/$1.Xauth
    if [ -e $GDM_AUTH_FILE ]; then
        SERVER_AUTH_FILE=$GDM_AUTH_FILE
        DISP_SEARCH_STRING="$1"
        return 0
    fi

    # Finally, check for startx

    for XPID in `ps -C X -o pid=`; do
        TRIAL_XAUTH_FILE=`tr '\0' '\n' < /proc/$XPID/environ | grep -e "^XAUTHORITY=" | cut -d= -f2`
        TRIAL_XAUTH_KEY=`xauth -f $TRIAL_XAUTH_FILE list | grep "unix$1"`
        if [ -n "$TRIAL_XAUTH_KEY" ]; then
            SERVER_AUTH_FILE=$TRIAL_XAUTH_FILE
            DISP_SEARCH_STRING="unix$1"
            return 0
        fi
    done

    # Couldn't find the key

    return 1
}

# Main part of script

#
# Since the daemon is usually started during init time before X comes up,
# $PATH may not yet contain the paths to the X binaries, particularly xauth.
# Add the usual location for where xauth may live and fail out if we still
# can't find it.
#

PATH=$PATH:/usr/bin:/usr/X11R6/bin
which xauth > /dev/null || exit -1

case "$1" in
    grant)
        GetServerAuthFile $2 || exit -1
        DISP_AUTH_KEY=`xauth -f $SERVER_AUTH_FILE list | grep $DISP_SEARCH_STRING | awk '{ print $3 }'`
        if [ -n "$DISP_AUTH_KEY" ]; then
            xauth -f $3 add $2 . $DISP_AUTH_KEY || exit -1
        else
            exit -1
        fi
        ;;

    revoke)
        xauth -f $3 remove $2 || exit -1
        ;;

    *)
        exit -1
        ;;
esac
exit 0
