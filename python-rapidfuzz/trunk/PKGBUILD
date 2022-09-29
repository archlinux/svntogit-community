# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>
# Contributor: Caltlgin Stsodaat <contact@fossdaily.xyz>

_pkgname=rapidfuzz
pkgname=python-$_pkgname
pkgver=2.10.2
pkgrel=1
pkgdesc='Rapid fuzzy string matching in Python using various string metrics'
arch=(x86_64)
url='https://github.com/maxbachmann/rapidfuzz'
license=(MIT)
depends=(python-jarowinkler)
makedepends=(python-build python-installer python-scikit-build python-rapidfuzz-capi)
checkdepends=(python-hypothesis python-pandas python-pytest)
optdepends=(python-numpy)
source=(https://files.pythonhosted.org/packages/source/${_pkgname::1}/$_pkgname/$_pkgname-$pkgver.tar.gz)
sha256sums=('26a80cfe249a3100f94737c0207626b0b6f3ac4e77077248599f6dbe7860a9d0')

build() {
  cd $_pkgname-$pkgver
  RAPIDFUZZ_BUILD_EXTENSION=1 \
  python -m build --wheel --no-isolation
}

check() {
  cd $_pkgname-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd $_pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm644 README.md -t "$pkgdir"/usr/share/doc/$pkgname
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
