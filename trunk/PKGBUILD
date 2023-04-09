# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-htmlhelp
pkgname=python-sphinxcontrib-htmlhelp
pkgver=2.0.1
pkgrel=3
pkgdesc='Sphinx extension which renders HTML help files'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-htmlhelp
license=('BSD')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
checkdepends=('python-html5lib' 'python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('0cbdd302815330058422b98a113195c9249825d681e18f11e8b1f78a2f11efff')
b2sums=('922921a52c421bde9787df6fd5107a515bb0af4f4a6a6c8b84f474b9d7b0ce9251437b8780b3464190e494555bbe6d72604e155bce98794c36c03ddbcc5c4cc7')

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
  ln -s "$site_packages"/sphinxcontrib_htmlhelp-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
