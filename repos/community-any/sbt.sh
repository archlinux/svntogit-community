#!/bin/sh

# https://github.com/sbt/sbt-launcher-package/blob/full-packaging/src/scripts/sbt-launch-lib.bash#L78
get_mem_opts () {
    local mem=${1:-1536}
    local perm=$(( $mem / 4 ))
    (( $perm > 256 )) || perm=256
    (( $perm < 1024 )) || perm=1024
    local codecache=$(( $perm / 2 ))

    echo "-Xms${mem}m -Xmx${mem}m -XX:MaxPermSize=${perm}m -XX:ReservedCodeCacheSize=${codecache}m"
}

if [[ -z "$SBT_OPTS" ]]; then
    SBT_OPTS=$(get_mem_opts)
fi

"$JAVA_HOME/bin/java" $SBT_OPTS -jar /usr/share/java/sbt/sbt-launch.jar "$@"
