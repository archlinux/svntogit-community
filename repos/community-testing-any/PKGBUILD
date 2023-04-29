# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor:  Chris Severance aur.severach aATt spamgourmet dott com

_name=pathspec
pkgname=python-pathspec
pkgver=0.11.1
pkgrel=3
pkgdesc='Utility library for gitignore style pattern matching of file paths'
arch=('any')
url=https://github.com/cpburnz/python-pathspec
license=('MPL2')
depends=('python')
makedepends=('python-build' 'python-flit-core' 'python-installer'
             'python-wheel')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('2798de800fa92780e33acca925945e9a19a133b715067cf165b8866c15a31687')
b2sums=('a97d838584959b5be5bb055773b2b8c6992d0b1f9ab2d8116adf251762c534fe9af976cf9cc9b9aae9f12de519ee3d609315ed608e543d0028c6ccc87cffbd8c')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
 cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m unittest discover tests
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
