# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.3
pkgrel=1
pkgdesc='Python compiler that produces faster executables and depends on libpython'
arch=(any)
url='https://nuitka.net/'
license=(APACHE)
depends=(python)
makedepends=(python-setuptools)
options=(!emptydirs)
optdepends=('chrpath: for building standalone executables')
source=("$pkgname-$pkgver.tgz::https://github.com/Nuitka/Nuitka/archive/$pkgver.tar.gz")
sha256sums=('f79e2612db748590c1a67b94523167f39e62a561b59fe8c688ca37224e36f35b')
validpgpkeys=('D96ADCA1377F1CEB6B5103F11BFC33752912B99C') # Kay Hayen

package() {
  cd "Nuitka-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
}

# getver: pypistats.org/packages/nuitka
# vim: sw=2 ts=2 et:
