# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
pkgver=2022.06.15 
pkgrel=1
pkgdesc="Python package for providing Mozilla's CA Bundle (using system CA store)"
arch=(any)
url="https://github.com/certifi/python-certifi"
license=('GPL')
depends=('python' 'ca-certificates')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://github.com/certifi/python-certifi/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('ffd2b2f38ff297cb49a6efe912d43b5b87bc028c8ee44f07276ac3a2a98186692e496b5579a544bfee2724214aa6e91397c679837ee856513cc8635e3470f34f')

prepare() {
  cd python-certifi-$pkgver
  # Use system CA store. Replacing the copy in the source tree so the test suite is actually run against it.
  ln -sf /etc/ssl/certs/ca-certificates.crt certifi/cacert.pem
  # Our CA store has non-ASCII comments, but we are not packaging for JVM
  # https://github.com/certifi/python-certifi/issues/50
  sed -i 's/encoding="ascii"/encoding="utf-8"/' certifi/core.py
}

build() {
  cd python-certifi-$pkgver
  python setup.py build
}

check() {
  cd python-certifi-$pkgver
  pytest
}

package() {
  cd python-certifi-$pkgver
  python setup.py install --skip-build -O1 --root="$pkgdir"

  # Replace CA store here again because the symlink was installed as a file
  ln -sf /etc/ssl/certs/ca-certificates.crt "$pkgdir"/usr/lib/python3.10/site-packages/certifi/cacert.pem

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
