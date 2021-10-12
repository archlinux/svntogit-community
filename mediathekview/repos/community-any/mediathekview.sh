#!/usr/bin/env sh

PATH="/usr/lib/jvm/java-17-openjdk/bin:${PATH}"
# requires preview features: https://github.com/mediathekview/MediathekView/issues/528
java -jar /usr/share/java/mediathekview/MediathekView.jar "$@"
