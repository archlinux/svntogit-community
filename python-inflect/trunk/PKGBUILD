# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.6.1
pkgrel=1
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=(any)
url="https://github.com/jazzband/inflect"
license=(MIT)
depends=(python)
makedepends=(python-build python-installer python-setuptools-scm python-toml python-wheel)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('d908786d82e56871344aee716a2b8dd8da51b0f47af363916b47bceb04468ce6f3c321f5f429e12b10f06c100b0a2ebc249b94110518f33ed0844694cf0f108f')
b2sums=('c465a962abbdda852fd778d09e3966bdb06dd34f56ef624a3f7d63e277b6e178d891aa23709d6591fe31a07acb3c25a7640aabb790ddf4493df82ab735963f98')

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
