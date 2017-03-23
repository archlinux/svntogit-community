## Bash completion for the Android SDK tools.
##
## Copyright (c) 2009 Matt Brubeck
##
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
##
## The above copyright notice and this permission notice shall be included in
## all copies or substantial portions of the Software.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
## IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
## FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
## AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
## LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
## OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
## THE SOFTWARE.


function _adb()
{
  local cur prev opts cmds c subcommand device_selected
  COMPREPLY=()
  cur="${COMP_WORDS[COMP_CWORD]}"
  prev="${COMP_WORDS[COMP_CWORD-1]}"
  opts="-d -e -s -p"
  cmds="devices push pull sync shell emu logcat forward jdwp install sideload \
        uninstall bugreport help version wait-for-device start-server \
        reboot reboot-bootloader \
        connect disconnect \
        kill-server get-state get-serialno status-window remount root ppp backup restore"
  cmds_not_need_device="devices help version start-server kill-server connect disconnect"
  subcommand=""
  device_selected=""

  # Look for the subcommand.
  c=1
  while [ $c -lt $COMP_CWORD ]; do
    word="${COMP_WORDS[c]}"
    if [ "$word" = "-d" -o "$word" = "-e" -o "$word" = "-s" ]; then
      device_selected=true
      opts="-p"
    fi
    for cmd in $cmds; do
      if [ "$cmd" = "$word" ]; then
        subcommand="$word"
      fi
    done
    c=$((++c))
  done

  case "${subcommand}" in
    '')
      case "${prev}" in
        -p)
          return 0;
          ;;
        -s)
          # Use 'adb devices' to list serial numbers.
          COMPREPLY=( $(compgen -W "$(adb devices |
                awk '/(device|recovery|sideload)$/{print $1}')" -- ${cur} ) )
          return 0
          ;;
      esac
      case "${cur}" in
        -*)
          COMPREPLY=( $(compgen -W "$opts" -- ${cur}) )
          return 0
          ;;
      esac
      if [ -z "$device_selected" ]; then
        local num_devices=$(( $(adb devices 2>/dev/null|wc -l) - 2 ))
        if [ "$num_devices" -gt "1" ]; then
          # With multiple devices, you must choose a device first.
          COMPREPLY=( $(compgen -W "${opts} ${cmds_not_need_device}" -- ${cur}) )
          return 0
        fi
      fi
      COMPREPLY=( $(compgen -W "${cmds}" -- ${cur}) )
      return 0
      ;;
    install)
      case "${cur}" in
        -*)
          COMPREPLY=( $(compgen -W "-l -r -s" -- ${cur}) )
          return 0
          ;;
      esac
      ;;
    forward)
      # Filename or installation option.
      COMPREPLY=( $(compgen -W "tcp: localabstract: localreserved: localfilesystem: dev: jdwp:" -- ${cur}) )
      return 0
      ;;
    uninstall)
      case "${cur}" in
        -*)
          COMPREPLY=( $(compgen -W "-k" -- ${cur}) )
          return 0
          ;;
      esac
      ;;
    logcat)
      case "${cur}" in
        -*)
          COMPREPLY=( $(compgen -W "-v -b -c -d -f -g -n -r -s" -- ${cur}) )
          return 0
          ;;
      esac
      case "${prev}" in
        -v)
          COMPREPLY=( $(compgen -W "brief process tag thread raw time long" -- ${cur}) )
          return 0
          ;;
        -b)
          COMPREPLY=( $(compgen -W "radio events main" -- ${cur}) )
          return 0
          ;;
      esac
      ;;
    backup)
      case "${cur}" in
        -*)
          COMPREPLY=( $(compgen -W "-f -apk -noapk -obb -noobb -shared -noshared -all -system -nosystem" -- ${cur}) )
          return 0
          ;;
      esac
      ;;
  esac
}
complete -o default -F _adb adb
