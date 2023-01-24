# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-applehelp
pkgname=python-sphinxcontrib-applehelp
pkgver=1.0.4
pkgrel=1
pkgdesc='Sphinx extension which outputs Apple help books'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-applehelp
license=('BSD')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('828f867945bbe39817c210a1abfd1bc4895c8b73fcaade56d45357a348a07d7e')
b2sums=('02a68ab585ecc8429056aa00c2ac3f0f555857cf649238a8df5cb1d39f1cd9c91d637ef55f2247df311b656e74a961b0418a1c552122b2a88ea160db5f996ee3')

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
