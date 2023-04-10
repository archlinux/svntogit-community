# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
pkgver=2022.12.07
pkgrel=3
pkgdesc="Python package for providing Mozilla's CA Bundle (using system CA store)"
arch=(any)
url="https://github.com/certifi/python-certifi"
license=(MPL2)
depends=(ca-certificates python)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest)
source=(https://github.com/certifi/python-certifi/archive/$pkgver/$pkgname-$pkgver.tar.gz)
sha512sums=('4e255c0d5998e98c999464ea27dff61831e97de2c812d7b06feb7ad1038c3070f2e48c58fc939485f5d806d419f0273716442c3c86165b861f0d81f0b3393f6b')

prepare() {
  cd $pkgname-$pkgver
  # Use system CA store. Replacing the copy in the source tree so the test suite is actually run against it.
  ln -sf /etc/ssl/certs/ca-certificates.crt certifi/cacert.pem
  # Our CA store has non-ASCII comments, but we are not packaging for JVM
  # https://github.com/certifi/python-certifi/issues/50
  sed -i 's/encoding="ascii"/encoding="utf-8"/' certifi/core.py
}

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $pkgname-$pkgver
  pytest
}

package() {
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Replace CA store here again because the symlink was installed as a file
  ln -sf /etc/ssl/certs/ca-certificates.crt "$pkgdir"/$site_packages/certifi/cacert.pem

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
