# Maintainer: David Runge <dvzrv@archlinux.org>

_name=flit-core
pkgname=python-flit-core
pkgver=3.8.0
pkgrel=5
pkgdesc="A PEP 517 build backend for packages using Flit"
arch=(any)
url="https://github.com/pypa/flit/tree/main/flit_core"
license=(BSD)
depends=(python python-tomli)
makedepends=(python-build python-installer)
checkdepends=(python-pytest python-testpath)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/${_name/-/_}-$pkgver.tar.gz)
sha512sums=('914804e3f2040762381afe039272d9d6fdbcd3f3cf8b9eea854f2f1d95edcb01718fd6685476bc1cdc251dfc46ef80b40f087df881d8b963dcc3f3332fd32a46')
b2sums=('20d0b1e245280938b1edfa83531907775af9da30cc6e1446d578eafc7e14184d3c8fb80f446d265456ea5ea587c51edfdb706793a8894916525b3ebba322b3b0')

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
