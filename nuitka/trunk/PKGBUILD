# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.0.5
pkgrel=1
pkgdesc='Python compiler that produces faster executables, but depends on libpython'
arch=('any')
url='https://nuitka.net/'
license=('APACHE')
depends=('python')
makedepends=('python-setuptools')
options=('!emptydirs')
optdepends=('chrpath: for building standalone executables')
source=("https://nuitka.net/releases/Nuitka-$pkgver.tar.bz2"{,.sig})
sha256sums=('5e9bedd1605a81195d0f999cc08fdeb385ec10649d5f654b2052a801e7c51254'
            'SKIP')
validpgpkeys=('D96ADCA1377F1CEB6B5103F11BFC33752912B99C') # Kay Hayen

package() {
  cd "Nuitka-$pkgver"

  python setup.py install --root="$pkgdir" --optimize=1
}

# getver: -u 3 nuitka.net/pages/download.html
# vim: sw=2 ts=2 et:
