CMD_SEARCH_ENABLED=0
[ -f /etc/pkgtools/pkgfile.conf     ] && CMD_SEARCH_ENABLED=`. /etc/pkgtools/pkgfile.conf;     echo $CMD_SEARCH_ENABLED`
[ -f "$HOME/.pkgtools/pkgfile.conf" ] && CMD_SEARCH_ENABLED=`. "$HOME/.pkgtools/pkgfile.conf"; echo $CMD_SEARCH_ENABLED` 
 
# Load shell-specific pkgfile hook
# Determine our shell without using $SHELL, which may lie
#   (trick adapted from /etc/profile)
if [ $CMD_SEARCH_ENABLED -eq 1 ]; then
    if [ -f /proc/mounts ]; then
        case $(/bin/readlink /proc/$$/exe) in
            /bin/bash) [ -f /usr/share/pkgtools/pkgfile-hook.bash ] && . /usr/share/pkgtools/pkgfile-hook.bash ;;
            /bin/zsh)  [ -f /usr/share/pkgtools/pkgfile-hook.zsh  ] && . /usr/share/pkgtools/pkgfile-hook.zsh  ;;
        esac
    fi
fi
unset CMD_SEARCH_ENABLED
