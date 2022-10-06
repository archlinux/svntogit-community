# Maintainer: David Runge <dvzrv@archlinux.org>

_name=sphinx-argparse
pkgname=python-sphinx-argparse
pkgver=0.3.2
pkgrel=1
pkgdesc="Sphinx extension that automatically documents argparse commands and options"
arch=(any)
url="https://github.com/ashb/sphinx-argparse"
license=(MIT)
depends=(python-sphinx)
makedepends=(python-build python-installer python-poetry-core python-wheel)
checkdepends=(python-pytest)
optdepends=('python-commonmark: markdown support')
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('5029b5ce0f79f37e134b36a800713bbbc1fd24c2013447ed0e0656b41527a2f709ce6b4201138dae678ceb9d03e288a42353bfec1bf5868e9f7881e563906c05')
b2sums=('dbd96475ebb2857a536eb075cee6cd54f08897beb8dd37e6e6a2f098c9758a8e13e0a54d96ff7f9e84dadc6b6ff1af38766cae0c7951cc4b27e3f6f753a81971')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_name-$pkgver
  pytest -vv
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
# vim:set ts=2 sw=2 et:
