# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgbase=python-pkgconfig
pkgname=(python2-pkgconfig python-pkgconfig)
pkgver=1.5.1
pkgrel=1
pkgdesc="Python module to interface with the pkg-config command line tool"
arch=(any)
url="https://github.com/matze/pkgconfig"
license=(MIT)
makedepends=(python-setuptools python2-setuptools)
source=("https://pypi.io/packages/source/p/pkgconfig/pkgconfig-$pkgver.tar.gz")
sha256sums=('97bfe3d981bab675d5ea3ef259045d7919c93897db7d3b59d4e8593cba8d354f')

package_python2-pkgconfig() {
  depends=(python2)
  cd pkgconfig-$pkgver

  python2 setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python-pkgconfig() {
  depends=(python)
  cd pkgconfig-$pkgver
  
  python setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
