# Maintainer: David Runge <dvzrv@archlinux.org>

_name=sphinx_lv2_theme
pkgname=python-sphinx-lv2-theme
pkgver=1.4.0
pkgrel=1
pkgdesc="A minimal static theme for Sphinx"
arch=(any)
url="https://gitlab.com/lv2/sphinx_lv2_theme"
license=(ISC)
depends=(
  python
  python-sphinx
)
makedepends=(
  python-build
  python-installer
  python-setuptools
  python-wheel
)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha256sums=('68834c4ff84da0e60e2fa8ebe87e83ceb8e5f5ad407d706d3b0e88c6958a92e5')
b2sums=('aa704fc220dd042467a4ab63e2e556d1b8f50bc60a6f1c367e9acbde3f664300d7ace89f5c56862b0a4339c8e0aafd744c693864c6059d47ef08c1a7dc1857b8')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
  install -vDm 644 {NEWS,README.md} -t "$pkgdir/usr/share/doc/$pkgname/"
}
