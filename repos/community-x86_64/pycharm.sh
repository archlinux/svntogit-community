#!/bin/sh

if [ -z "$PYCHARM_JDK" ] ; then
  PYCHARM_JDK="/usr/lib/jvm/java-8-openjdk/"
fi
exec env PYCHARM_JDK=$PYCHARM_JDK /usr/share/pycharm/bin/pycharm.sh $@

# vim: ts=2 sw=2 et:

