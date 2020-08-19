#!/usr/bin/env sh

PATH="/usr/lib/jvm/java-14-openjdk/bin:${PATH}"
# requires preview features: https://github.com/mediathekview/MediathekView/issues/528
java -jar --enable-preview /usr/share/java/mediathekview/MediathekView.jar "$@"
