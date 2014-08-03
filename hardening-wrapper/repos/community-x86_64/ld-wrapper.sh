#!/bin/bash

. /usr/lib/hardening-wrapper/common.sh

declare -A default
while IFS== read key value; do
  default["$key"]="$value"
done < /etc/hardening-wrapper.conf

force_bindnow="${HARDENING_BINDNOW:-"${default[HARDENING_BINDNOW]:-1}"}"
force_relro="${HARDENING_RELRO:-"${default[HARDENING_RELRO]:-1}"}"

case "$force_bindnow" in
  0) ;;
  1) arguments+=(-z now) ;;
  *) error 'invalid value for HARDENING_BINDNOW' ;;
esac

case "$force_relro" in
  0) ;;
  1) arguments+=(-z relro) ;;
  *) error 'invalid value for HARDENING_RELRO' ;;
esac

unwrapped=false
IFS=: read -ra path <<< "$PATH";
for p in "${path[@]}"; do
  binary="$p/${0##*/}"
  if [[ "$binary" != "$0" && -x "$binary" ]]; then
    unwrapped="$binary"
    break
  fi
done

exec "$unwrapped" "${arguments[@]}" "$@"
