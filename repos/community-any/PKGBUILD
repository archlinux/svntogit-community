# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=6.4.1
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-packaging' 'python-setuptools' 'python-tomli')
checkdepends=('git' 'mercurial' 'python-pip' 'python-pytest'
              'python-virtualenv')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('9bd9ff7fd5fa1cf469fe28a632336b9cfd351476c6d09379ff676d3945f669b9')
b2sums=('984b60de24e3090bfa7284ef91f40cfb8481cd9008d57012564e6631727dc1e1bb6820265a4fd3576581ce836224599bdd8ddef73446ddc3040e51ddad4b6140')

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
