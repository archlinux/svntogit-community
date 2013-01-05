# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=('python-pytz' 'python2-pytz')
pkgver=2012j
pkgrel=1
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
makedepends=('python' 'python2')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2{,.asc})
md5sums=('2b20917e67917b38f74f720bf2cadcf1'
         '2f3f6d3ef6c92a617a84cca74406ff2b')

check(){
    cd $srcdir/pytz-$pkgver/pytz/tests

    python3 test_tzinfo.py

    python2 test_tzinfo.py

}

package_python-pytz(){
    depends=('python')
    pkgdesc="Cross platform time zone library for Python"

    cd $srcdir/pytz-$pkgver

    python3 setup.py install --root=$pkgdir/



    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}


package_python2-pytz(){
    depends=('python2')
    pkgdesc="Cross platform time zone library for Python"

    cd $srcdir/pytz-$pkgver

    # python 2 fix
    sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' pytz/tzfile.py

    python2 setup.py install --root="$pkgdir/"

    install -D LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
