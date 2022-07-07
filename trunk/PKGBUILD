# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor : Ionut Biru <ibiru@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

_name=docutils
pkgname=python-docutils
pkgver=0.19
pkgrel=1
epoch=1
pkgdesc='Set of tools for processing plaintext docs into formats such as HTML, XML, or LaTeX'
arch=('any')
url='http://docutils.sourceforge.net'
license=('custom')
depends=('python')
makedepends=('python-setuptools')
source=("https://downloads.sourceforge.net/$_name/$_name-$pkgver.tar.gz")
sha512sums=('fb904a899f2b6f3c07c5079577bd7c52a3182cb85f6a4149391e523498df15bfa317f0c04095b890beeb3f89c2b444875a2a609d880ac4d7fbc3125e46b37ea5')

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
