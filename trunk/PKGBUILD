# Maintainer: David Runge <dvzrv@archlinux.org>

_name=flit-core
pkgname=python-flit-core
pkgver=3.9.0
pkgrel=1
pkgdesc="A PEP 517 build backend for packages using Flit"
arch=(any)
url="https://github.com/pypa/flit/tree/main/flit_core"
license=(BSD)
depends=(python)
makedepends=(
  python-build
  python-installer
)
checkdepends=(
  python-pytest
  python-testpath
)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/${_name/-/_}-$pkgver.tar.gz)
sha512sums=('1205589930d2c51d6aa6b2533a122a912e63b157e94adba2a0649a58d324fa98a5b84609d9b53e9d236f1cdb6a6984de2cefcf2f11abc2cd83956df21f269ad6')
b2sums=('2fb053655a494736f5f9ce2d2c193d5d98622e410c0c0f18c92eb62d32ff98cbe830a1728461ed7e7e087d2fcf5f6a0c912717c2d534be688d688c4714c6865b')

build() {
  cd ${_name/-/_}-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd ${_name/-/_}-$pkgver
  pytest -vv
}

package() {
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd ${_name/-/_}-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"

  # remove tests
  rm -frv "$pkgdir/$site_packages/${_name/-/_}/tests/"
  # remove vendored tomli
  rm -frv "$pkgdir/$site_packages/${_name/-/_}/vendor/"
}
