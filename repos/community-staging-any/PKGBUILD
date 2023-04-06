# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-localzone
pkgver=0.9.8
pkgrel=4
pkgdesc="A simple library for managing DNS zones"
url="https://localzone.iomaestro.com/"
license=('BSD')
arch=('any')
depends=('python-dnspython')
makedepends=('python-setuptools')
source=("https://pypi.io/packages/source/l/localzone/localzone-$pkgver.tar.gz")
sha512sums=('912ee187f57dcb275d3c23d0b24397c12991d1c89e4c9931f4741e1d8ec76f8c41e0ab799150052062726921d5d92f8d98fa15d39fd5357032abc22dc1fe2afe')

build() {
  cd localzone-$pkgver
  python setup.py build
}

package() {
  cd localzone-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
