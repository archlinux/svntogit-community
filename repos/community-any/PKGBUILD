# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.5.33
pkgrel=1
pkgdesc='Python to native compiler'
arch=('any')
url='https://nuitka.net/'
license=('APACHE')
depends=('python')
makedepends=('python-setuptools')
options=('!emptydirs')
optdepends=('chrpath: for building standalone executables')
source=("https://nuitka.net/releases/Nuitka-${pkgver%.0}.tar.gz"{,.sig})
sha256sums=('9a4b5be2c5ea2f0a32adfc3efd2b1a19e17c6b5daa81879f760674aec6262b30'
            'SKIP')
validpgpkeys=('D96ADCA1377F1CEB6B5103F11BFC33752912B99C') # Kay Hayen

package() {
  cd "Nuitka-${pkgver%.0}"

  python setup.py install --root="$pkgdir" --optimize=1
}

# getver: nuitka.net/pages/download.html
# vim: sw=2 ts=2 et:
