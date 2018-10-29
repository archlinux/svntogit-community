# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=('python-pytz' 'python2-pytz')
pkgver=2018.7
pkgrel=1
arch=('any')
url="http://pypi.python.org/pypi/pytz"
license=("MIT")
makedepends=('python' 'python2')
source=("https://pypi.io/packages/source/p/pytz/pytz-${pkgver}.tar.gz")
md5sums=('4b91594c440aa20c76ac92043efa75e1')
validpgpkeys=('C7ECC365AB6F255E1EB9BA1701FA998FBAC6374A')

build(){
    cp -rf pytz-$pkgver pytz2-$pkgver
}

check(){
    cd pytz-$pkgver/pytz/tests

    python3 test_tzinfo.py
    python2 test_tzinfo.py
}

package_python-pytz(){
    depends=('python')
    pkgdesc="Cross platform time zone library for Python"

    cd pytz-$pkgver

    python3 setup.py install --root=$pkgdir/

    install -D LICENSE.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE
}


package_python2-pytz(){
    depends=('python2')
    pkgdesc="Cross platform time zone library for Python"

    cd pytz2-$pkgver

    python2 setup.py install --root="$pkgdir/"

    install -D LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
