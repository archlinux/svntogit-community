#!/bin/sh
if [ -z "$IDEA_JDK" ] ; then
	IDEA_JDK="/usr/lib/jvm/java-8-openjdk/"
fi
exec env IDEA_JDK=$IDEA_JDK /usr/share/intellijidea-ce/bin/idea.sh $@
