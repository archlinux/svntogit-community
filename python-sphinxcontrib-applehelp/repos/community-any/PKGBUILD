# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib.applehelp
pkgname=python-sphinxcontrib-applehelp
pkgver=1.0.3
pkgrel=1
pkgdesc='Sphinx extension which outputs Apple help books'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-applehelp
license=('BSD')
makedepends=('python-build' 'python-flit-core' 'python-installer'
             'python-wheel')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('83749f09f6ac843b8cb685277dbc818a8bf2d76cc19602699094fe9a74db529e')
b2sums=('3fc12ede9a0cb713f5c68942a41fbb14e160a104fc2ce6425ee61f3f6a11448ab6ab0492a86d1637a596a27bf86fc2876eb96579e234f87b81e19e74b90335e3')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/sphinxcontrib_applehelp-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
