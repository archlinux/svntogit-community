# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.8
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
sha512sums=('656df31fc41d07e2e0a288834e73cd63066ebeef3e4aa65c118d9a25baaead2eb4045d9b34e52eaf3ac006adbf1c1848d55c12292a59a18be86ccf1e64e819d3')
validpgpkeys=('D96ADCA1377F1CEB6B5103F11BFC33752912B99C') # Kay Hayen

package() {
  cd "Nuitka-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
}

# getver: pypistats.org/packages/nuitka
# vim: sw=2 ts=2 et:
