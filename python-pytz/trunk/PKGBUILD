# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=('python-pytz' 'python2-pytz')
pkgver=2014.1
pkgrel=1
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
makedepends=('python' 'python2')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2{,.asc})
md5sums=('ef8f772d2cbdf5900eeb7c1052e5edf5'
         'SKIP')

build(){
    cd $srcdir
    cp -rf pytz-$pkgver pytz2-$pkgver
}

check(){
    cd $srcdir/pytz-$pkgver/pytz/tests

    python3 test_tzinfo.py

    python2 test_tzinfo.py

}

package_python-pytz(){
    depends=('python')
    pkgdesc="Cross platform time zone library for Python"

    cd $srcdir/pytz-$pkgver

    # Fix locale https://github.com/ipython/ipython/issues/2057
    export LC_ALL=en_US.UTF-8

    python3 setup.py install --root=$pkgdir/

    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}


package_python2-pytz(){
    depends=('python2')
    pkgdesc="Cross platform time zone library for Python"

    cd $srcdir/pytz2-$pkgver

    # python 2 fix
    sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' pytz/tzfile.py

    python2 setup.py install --root="$pkgdir/"

    install -D LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
