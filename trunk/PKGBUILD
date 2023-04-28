# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: xantares

_name=alabaster
pkgname=python-sphinx-alabaster-theme
pkgver=0.7.13
pkgrel=4

pkgdesc="Sphinx default theme"
url='https://github.com/sphinx-doc/alabaster'
arch=('any')
license=('custom:BSD')

depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')

source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")

sha256sums=('a27a4a084d5e690e16e01e03ad2b2e552c61a65469419b907243193de1a84ae2')
b2sums=('b67ab19b3cb4d86bc0f2bc94cbac7de42b6ffc089844d49daa5db40de942dd87555f9ed8ac362ea01904a9e77f8fe995250bd878b39c9a4851041cec8ef6460e')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
