# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor : Ionut Biru <ibiru@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

_name=docutils
pkgname=python-docutils
pkgver=0.17.1
pkgrel=2
pkgdesc='Set of tools for processing plaintext docs into formats such as HTML, XML, or LaTeX'
arch=('any')
url='http://docutils.sourceforge.net'
license=('custom')
depends=('python')
makedepends=('python-setuptools')
source=("https://downloads.sourceforge.net/$_name/$_name-$pkgver.tar.gz")
sha512sums=('5ec2087116bd5356fdffc54f07f6b0355aac5fa9d6caeefa77e8d201fd4706c0d419193c4d9a3964ae493da3091fe2c7dc36b74f81a1e1b9282173658b06e71b')

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
