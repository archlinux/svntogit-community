# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=6.3.2
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-packaging' 'python-setuptools' 'python-tomli')
checkdepends=('git' 'mercurial' 'python-pip' 'python-pytest'
              'python-virtualenv')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('a49aa8081eeb3514eb9728fa5040f2eaa962d6c6f4ec9c32f6c1fba88f88a0f2')
b2sums=('4291f3810dc5ea111a6bad1bf37c8704a7eb6cdd112ea476d629d6175c43cc7d8f78d450181c0e588a5f3fc0fc092fedb41fcb6e198a42f730f9fc6b8d96e343')

build() {
  cd $_name-$pkgver
  python setup.py build
  python setup.py egg_info
}

check() {
  cd $_name-$pkgver
  mkdir -p temp
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  python setup.py install --root=temp --optimize=1 --skip-build
  PYTHONPATH="$PWD/temp/$site_packages" pytest
}

package() {
  cd $_name-$pkgver
  python setup.py install --root "$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}
