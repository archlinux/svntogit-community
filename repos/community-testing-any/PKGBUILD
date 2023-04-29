# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=0.4.27
pkgrel=3
epoch=1
pkgdesc="A python wrapper for libmagic"
arch=(any)
url="https://github.com/ahupp/python-magic"
depends=(
  file
  python
)
makedepends=(
  python-build
  python-installer
  python-setuptools
  python-wheel
)
checkdepends=(python-pytest)
license=(MIT)
# tests not in pypi sdist tarball
# source=(https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz)
source=($pkgname-$pkgver.tar.gz::https://github.com/ahupp/$pkgname/archive/refs/tags/$pkgver.tar.gz)
sha512sums=('a476730a5caa9a2a784187f57743d5cec4b1829a6a76d4d1fb4e0112caf5487888961df293bc38074ef1a5d313b0fc4aed4cc99b980f5336e8a907c44a33e84e')
b2sums=('4ba22d0f8bd5e70eb37e3b46eba1b885d49682bf45d703ad7966bcc67614427ebe597e3100575f863b7e54421c6de6fc875af24a9d5b49742fe07b361b65f198')

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  local pytest_options=(
    --deselect test/python_magic_test.py::MagicTest::test_extension
  )

  cd $pkgname-$pkgver
  LC_ALL=en_US.UTF-8 pytest -vv "${pytest_options[@]}"
}

package() {
  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
