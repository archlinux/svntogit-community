#!/bin/sh

if [ -z "$IDEA_JDK" ] ; then
  IDEA_JDK="/usr/lib/jvm/java-8-openjdk/"
fi
exec env IDEA_JDK=$IDEA_JDK /usr/share/idea/bin/idea.sh $@

# vim: ts=2 sw=2 et:

