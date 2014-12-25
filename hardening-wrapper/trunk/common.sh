error() {
  printf "%s\n" "$1" >&2
  exit 1
}

run_wrapped_binary() {
  # search for the wrapped binary in $PATH
  #
  # ignore paths before our own for compatibility with other wrappers
  unwrapped=false
  self=false
  IFS=: read -ra path <<< "$PATH";
  for p in "${path[@]}"; do
    binary="$p/${0##*/}"
    if $self && [[ -x "$binary" ]]; then
      unwrapped="$binary"
      break
    elif [[ "$binary" -ef "$0" ]]; then
      self=true
    fi
  done

  exec "$unwrapped" "${arguments[@]}" "$@"
}
