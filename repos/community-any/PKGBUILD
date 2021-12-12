# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor : Ionut Biru <ibiru@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

_name=docutils
pkgname=python-docutils
pkgver=0.16
pkgrel=2
epoch=1
pkgdesc='Set of tools for processing plaintext docs into formats such as HTML, XML, or LaTeX'
arch=('any')
url='http://docutils.sourceforge.net'
license=('custom')
depends=('python')
makedepends=('python-setuptools')
source=("https://downloads.sourceforge.net/$_name/$_name-$pkgver.tar.gz")
sha512sums=('1a4e1bdedc79388e73dd438ae6d4d2ba67a005c745613452e027c0f6b378058b528f3329d650454fc0d3dd5253a1eb95dc52b35846cbfb4d8618d9bd4c3ad934')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  # we need utf locale to valid utf8 tests
  export LANG=en_US.UTF-8
  PYTHONPATH="$PWD/build/python/" python test/alltests.py
}

package() {
  cd $_name-$pkgver
  python setup.py build install --root="$pkgdir" --optimize=1
  # symlink without .py
  for f in "$pkgdir"/usr/bin/*.py; do
      ln -s "$(basename $f)" "$pkgdir/usr/bin/$(basename $f .py)"
  done
  # setup license
  install -D -m644 COPYING.txt "$pkgdir/usr/share/licenses/$pkgname/COPYING.txt"
  install -D -m644 licenses/python* "$pkgdir/usr/share/licenses/$pkgname/"
}

# vim:set ts=2 sw=2 et:
