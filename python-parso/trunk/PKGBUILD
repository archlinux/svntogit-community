# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>

_pkgbase=parso
pkgname=python-parso
pkgver=0.6.2
pkgrel=1
pkgdesc="Python parser that supports error recovery and round-trip parsing for different Python versions"
arch=('any')
url="https://github.com/davidhalter/parso"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/davidhalter/parso/archive/v$pkgver.tar.gz" "python3.8.2-compat.patch")
sha512sums=('da011c6fbab3ca2157c8934086cc0db0b7a37f5cd67debe70f56429f409de8762b124948ee75ac65779b806d8aaab759ee790eacb580910f3609ffd280dba2a8'
            '819f1e5821cdb992dff2d5e6fed0bc57694f8acd2ceb7560eaa084e5f1662c1bc65d16d88de82414d93d2d83e73cd093ef61120dbecca377b55cf8ab6989a506')

prepare() {
  cd "$_pkgbase-$pkgver"
  patch -Np1 -i ${srcdir}/python3.8.2-compat.patch
}

check() {
  cd "$_pkgbase-$pkgver"
  pytest test
}

package_python-parso() {
  cd "$_pkgbase-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=1

  install -D -m644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
