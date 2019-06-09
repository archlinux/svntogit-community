# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.4
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
sha256sums=('ee22751ecc91d2ec957db8575d0b350b5aea03fe11576fe4a9276903c149d7a2')
validpgpkeys=('D96ADCA1377F1CEB6B5103F11BFC33752912B99C') # Kay Hayen

package() {
  cd "Nuitka-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
}

# getver: pypistats.org/packages/nuitka
# vim: sw=2 ts=2 et:
