#!/bin/bash
prompt_command () {
	if [ $? -eq 127 ]; then
		local _prev_command="$(history 1 | awk '{print $2}')"
		local pkgs="$(pkgfile -b -v "$_prev_command")"
		if [ ! -z "$pkgs" ]; then
			echo 
			echo "$_prev_command may be found in the following packages:"
			echo 
			echo -e "$pkgs"
		fi
	fi
}
PROMPT_COMMAND=prompt_command
