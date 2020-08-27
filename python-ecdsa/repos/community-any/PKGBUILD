# Maintainer: Angel Velasquez <angvp@archlinux.org>
# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-ecdsa
pkgname=('python-ecdsa' 'python2-ecdsa')
pkgver=0.16.0
pkgrel=1
pkgdesc="Implementation of ECDSA in Python"
arch=('any')
url="https://github.com/warner/python-ecdsa"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python-hypothesis')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/e/ecdsa/ecdsa-$pkgver.tar.gz" "LICENSE")
sha512sums=('94ccefe19899a5e56393bb0e6624e9af66bdc60ad370d65900a24a0465c430a3a001ed9c25970e48834cb25ca730bc9279af98d17ecd3ad66189c64c8f864b42'
            '5519af4e81ecb681e2ef1a26602efed1640d6e3bf100d8c492dd4bbce4dba75de6a5a308115ff78a8dcd5d428630a92dd88fe9abfaeed04cd066b3f4d288b219')

build() {
  cp -R "$srcdir/ecdsa-$pkgver" "$srcdir/ecdsa-$pkgver-py2"
  cd "$srcdir/ecdsa-$pkgver-py2"
  sed -ie 's#/usr/bin/env python#/usr/bin/env python2#' src/ecdsa/*.py
}

check() {
  cd "$srcdir/ecdsa-$pkgver"
  python -m pytest
}

package_python-ecdsa() {
  depends=('python')
  cd "$srcdir/ecdsa-$pkgver"
  python setup.py install --root="$pkgdir/" --optimize=1
  install -D -m644 "$srcdir/LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-ecdsa() {
  depends=('python2')
  cd "$srcdir/ecdsa-$pkgver-py2"
  python2 setup.py install --root="$pkgdir/" --optimize=1
  install -D -m644 "$srcdir/LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
