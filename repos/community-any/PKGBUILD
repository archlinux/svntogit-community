# Maintainer: David Runge <dvzrv@archlinux.org>

_name=inflect
pkgname=python-inflect
pkgver=5.6.2
pkgrel=1
pkgdesc="Correctly generate plurals, singular nouns, ordinals, indefinite articles"
arch=(any)
url="https://github.com/jazzband/inflect"
license=(MIT)
depends=(python)
makedepends=(python-build python-installer python-setuptools-scm python-toml python-wheel)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('0bf66803c888575be478d45c1ddaf96432b8883af2b854a874678643e7b92a6a1bc60eb0d6ee324346dd4df7482364a7525a40f04f31910263c840196ba49d38')
b2sums=('d20739928bc0a5e181456c3bbc583e5816bd87b615ad1f6c1ec6edede3a67614ff4a97db4973d940d2615f40958efcf24f0de3cecaaaf2e892defec322481b4c')

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
