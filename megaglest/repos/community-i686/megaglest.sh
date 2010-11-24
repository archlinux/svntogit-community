#!/bin/sh
 # Wrapper script for Megaglest.
 
 MAINDIR=/usr/share/megaglest
 BASEDIR="$HOME/.config"
 DIR="$BASEDIR/megaglest"
 if [ ! -d "$DIR" ]; then
 mkdir -p $DIR
 fi
 cd $DIR
 [ -f glest.ini ] || cp /usr/share/megaglest/glest.ini .
 [ -h megaglest ] || ln -s /usr/share/megaglest/megaglest .
 [ -f servers.ini ] || cp $MAINDIR/servers.ini .
 [ -f glestkeys.ini ] || cp $MAINDIR/glestkeys.ini .
 for i in data scenarios techs tilesets tutorials; do
 [ -h $i ] || ln -s $MAINDIR/$i .
 done
 [ -d maps ] || mkdir maps
 [ -d screens ] || mkdir screens
 cd maps
 for i in $MAINDIR/maps/*; do
 [ -h `basename $i` ] || ln -s $i .
 done
 cd ..
 
 exec ./megaglest