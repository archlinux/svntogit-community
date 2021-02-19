# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=python-pkgconfig
pkgver=1.5.2
pkgrel=1
pkgdesc="Python module to interface with the pkg-config command line tool"
arch=(any)
url="https://github.com/matze/pkgconfig"
license=(MIT)
depends=(python)
makedepends=(python-setuptools)
source=("https://pypi.io/packages/source/p/pkgconfig/pkgconfig-$pkgver.tar.gz")
sha256sums=('38d612488f0633755a2e7a8acab6c01d20d63dbc31af75e2a9ac98a6f638ca94')

package() {
  cd pkgconfig-$pkgver
  
  python setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
