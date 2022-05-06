#!/usr/bin/env bash
set -eu

# SPDX-License-Identifier: GFDL-1.3-or-later
# utility script to download all required sources for inspection

FILES=(
	'https://www.quicklisp.org/beta/index.html'
	'https://www.quicklisp.org/beta/faq.html'
	'https://beta.quicklisp.org/release-key.txt'
	'https://beta.quicklisp.org/quicklisp.lisp'
	'https://beta.quicklisp.org/quicklisp.lisp.asc'
)

# download files if they don't exist
for file in "${FILES[@]}"; do
	if [ ! -f "$(basename ${file})" ]; then
		curl --location --remote-name "$file"
	fi
done

if [ ! -f 'README.md' ]; then
	html2text index.html >README.md
fi

if [ ! -f 'FAQ.md' ]; then
	html2text faq.html >FAQ.md
fi

if [ ! -f 'LICENSE' ]; then
	sed -n '/Copyright/,/from the author./p' README.md | sed -e 's/^      //' >LICENSE
fi

# strip trailing whitespace from generated files
sed -e 's/[ \t]*$//' -i README.md FAQ.md LICENSE
