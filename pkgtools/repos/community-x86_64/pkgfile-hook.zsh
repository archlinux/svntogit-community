# Licensed under GPL, see COPYING for the whole text
#
# This script will look-up command in the database and suggest
# installation of packages available from the repository
#
function preexec() {
  command="${1%% *}"
}
 
function precmd() {
  (($?)) && [ -n "$command" ] && [ -x /usr/bin/pkgfile ] && {
    which -- "$command" >& /dev/null 
    if [ $? -ne 0 ]; then
      local pkgs="$(pkgfile -b -v "$command")"
      if [ ! -z "$pkgs" ]; then
        echo -e "\"$command\" may be found in the following packages:\n\n${pkgs}\n"
      fi
    fi
    unset command
  }
}
# vim: set filetype=zsh :
