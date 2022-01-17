# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=6.4.0
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-packaging' 'python-setuptools' 'python-tomli')
checkdepends=('git' 'mercurial' 'python-pip' 'python-pytest'
              'python-virtualenv')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('54f5b1dcccd28e7813236609e620671f23d548548d744270a07d8df6df623649')
b2sums=('752f6c541b05e5d63c66c20a3458e615fc774a4781f92a02aae37a64d971af536586cec3fabac8d5efebe3cf95c18c3e323ad650b4bd8c96a2b4a7808987bd7e')

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
