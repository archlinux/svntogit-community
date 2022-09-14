# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
pkgver=2022.06.15.2
pkgrel=1
pkgdesc="Python package for providing Mozilla's CA Bundle (using system CA store)"
arch=(any)
url="https://github.com/certifi/python-certifi"
license=(MPL2)
depends=('python' 'ca-certificates')
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=('python-pytest')
source=("https://github.com/certifi/python-certifi/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('bd6e3943d54b1c607231045ca60d8d386c46dafcec74546ec9c039f5b9d2331ce046f62bc088f67dc19f8230ac128b123b9ba1989d885a20798eec1474e46196')

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
  python -m build --wheel --no-isolation
}

check() {
  cd python-certifi-$pkgver
  pytest
}

package() {
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd python-certifi-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Replace CA store here again because the symlink was installed as a file
  ln -sf /etc/ssl/certs/ca-certificates.crt "$pkgdir"/$site_packages/certifi/cacert.pem

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
