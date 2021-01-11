#!/usr/bin/env sh

PATH="/usr/lib/jvm/java-15-openjdk/bin:${PATH}"
# requires preview features: https://github.com/mediathekview/MediathekView/issues/528
java --enable-preview -jar /usr/share/java/mediathekview/MediathekView.jar "$@"
