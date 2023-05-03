# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-devhelp
pkgname=python-sphinxcontrib-devhelp
pkgver=1.0.2
pkgrel=11
pkgdesc='Sphinx extension which outputs Devhelp document'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-devhelp
license=('BSD')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('ff7f1afa7b9642e7060379360a67e9c41e8f3121f2ce9164266f61b9f4b338e4')
b2sums=('fcf04148bc4a77963517d9011c20a6b77eee499f1a5dcd4a9631b4f415f80a9f7091b254f74ba2fbc9b7106dfb741dc839e14813e088d5a0802793ed457e95df')

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
  ln -s "$site_packages"/sphinxcontrib_devhelp-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
