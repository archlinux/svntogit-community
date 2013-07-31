#!/bin/bash

# Copyright © 2013 Sébastien Luttringer

# This script is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This script is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this script.  If not, see <http://www.gnu.org/licenses/>.

# Get and format official OUI
wget -O- 'http://standards.ieee.org/regauth/oui/oui.txt' | \
sed -nr 's/[ \t]+(..)-(..)-(..)[ \t]+\(hex\)[ \t]+(.*)/\L\1:\2:\3\E\t\4/p' > ethercodes.dat

# Add private OUI
cat >> ethercodes.dat <<EOF
52:54:00	QEMU Virtual NIC
b0:c4:20	Bochs Virtual NIC
de:ad:ca	PearPC Virtual NIC
00:ff:d1	Cooperative Linux virtual NIC
EOF

# Sort and compress
sort ethercodes.dat | xz -9 > ethercodes.dat.xz
rm ethercodes.dat
