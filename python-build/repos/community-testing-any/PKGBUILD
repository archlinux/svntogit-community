# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_pkgname=build
pkgname=python-$_pkgname
pkgver=0.10.0
pkgrel=3
pkgdesc='A simple, correct PEP 517 build frontend'
arch=('any')
url='https://github.com/pypa/build'
license=('MIT')
depends=('python-packaging' 'python-pyproject-hooks' 'python-tomli')
optdepends=('python-virtualenv: Use virtualenv for build isolation')
makedepends=('git' 'python-build' 'python-flit-core' 'python-installer'
             'python-sphinx' 'python-sphinx-argparse-cli' 'python-sphinx-autodoc-typehints' 'python-sphinx-furo')
checkdepends=('python-pytest' 'python-pytest-mock' 'python-pytest-rerunfailures' 'python-filelock' 'python-setuptools' 'python-toml' 'python-wheel')
source=("git+$url#tag=$pkgver?signed")
validpgpkeys=('3DCE51D60930EBA47858BA4146F633CBB0EB4BF2') # Filipe Laíns (FFY00) <lains@archlinux.org>
sha512sums=('SKIP')

build() {
  cd $_pkgname

  python -m build --wheel --skip-dependency-check --no-isolation

  PYTHONPATH=src sphinx-build -b dirhtml -v docs docs/build/html
}

check() {
  cd $_pkgname

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname

  python -m installer --destdir="$pkgdir" dist/*.whl

  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_pkgname-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
