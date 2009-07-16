# $Id: PKGBUILD,v 1.16 2009/04/08 21:07:01 dsa Exp $
# Maintainer: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-pytz
pkgver=2009d
pkgrel=1
pkgdesc="Cross platform time zone library for Python"
arch=('i686' 'x86_64')
url="http://sourceforge.net/projects/pytz"
license=("MIT")
depends=('python')
source=(http://pypi.python.org/packages/source/p/pytz/pytz-$pkgver.tar.bz2)

build() {
    cd $startdir/src/pytz-$pkgver
    python setup.py install --root=$startdir/pkg/ 
    install -D LICENSE.txt $startdir/pkg/usr/share/licenses/$pkgname/LICENSE
}
md5sums=('f1dfee0d4d5b424f0c6a8d93ddebfee7')
