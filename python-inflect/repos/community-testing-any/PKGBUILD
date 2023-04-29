# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=6.0.4
pkgrel=2
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=(any)
url="https://github.com/jazzband/inflect"
license=(MIT)
depends=(
  python
  python-pydantic
)
makedepends=(
  python-build
  python-installer
  python-setuptools-scm
  python-toml
  python-wheel
)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('96aaa74b3e8c5dcc91d81af336af73535826f3cedaa556d6baf540ca54db1a7c1f17a372c240446c0d81697520eab154bad4f0aad6195c6ab8e131ae443d3811')
b2sums=('24ec6f25462594fde4558f7a4269c68d31989ead54c982f3a4382b5f0c192fd5fcac7544413fecef0abaf7c3fe2f9b4a8049fc7dc7d324e4397fb6a81763ef8e')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  local _site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd $_name-$pkgver
  # install to temporary location, as importlib is used
  python -m installer --destdir=test_dir dist/*.whl
  export PYTHONPATH="test_dir/$_site_packages:$PYTHONPATH"
  pytest -vv
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 {CHANGES,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
