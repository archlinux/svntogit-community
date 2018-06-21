#!/bin/sh -x
wget https://www.rfc-editor.org/rfc/tar/RFC-all.tar.gz
wget https://www.rfc-editor.org/rfc/rfc-index.txt
scp RFC-all.tar.gz rfc-index.txt repos.archlinux.org:/srv/sources/other/community/rfc/
