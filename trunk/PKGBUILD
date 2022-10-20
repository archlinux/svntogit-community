# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=6.0.1
pkgrel=1
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=(any)
url="https://github.com/jazzband/inflect"
license=(MIT)
depends=(python python-pydantic)
makedepends=(python-build python-installer python-setuptools-scm python-toml python-wheel)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('8481644f52f975944f456c502759f7ce4ba2fbe07b0a77506a78c39763dcc5264d771e76efa95633c0a9cef34f47a5da6b2cf8d565c813edab6fef3286cb7afa')
b2sums=('dd9e69ca655dab761df87e4f536e5fc4a396df8376a3c00deef47763b2b83a0e1931b53db8d1192b1605c95831c8053749feef7548409e93c3602c8db1c5c504')

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
  pytest -vv -c /dev/null
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 {CHANGES,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
