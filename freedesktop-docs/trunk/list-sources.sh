#!/bin/bash

. PKGBUILD

for i in ${source[@]}; do
	if echo $i | grep -E '^git\+https://' >/dev/null; then
		URL=$(echo $i | sed 's|git+||' | cut -f1 -d#)
		HASH=$(git ls-remote $URL refs/heads/master | awk -- '{print $1}')
		echo "	\"git+$URL#commit=$HASH\""
	fi
done
