# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipenv-to-requirements
pkgver=0.9.0
pkgrel=8
pkgdesc="Generate requirements[-dev].txt from Pipfile using pipenv"
url="https://github.com/gsemet/pipenv-to-requirements"
license=('MIT')
arch=('any')
depends=('python-pbr' 'python-pipenv')
checkdepends=('python-pyfakefs' 'python-pytest-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/gsemet/pipenv-to-requirements/archive/$pkgver.tar.gz"
        $pkgname-pipenv-2022.10.9.patch::https://github.com/gsemet/pipenv-to-requirements/pull/26.patch)
sha512sums=('f89be89e120cc3d9a543c8efc1ff4c517f3d47145133a7db2f842dcbf168099588a2d281b7fb69b6ddf63439fbdebafd683b258a349cc7ad50efd454495caf14'
            'e2983bcb87c83af2a86ee49a5e8027ac1af830582caaec1bc85706f046686a9ce1e60e35dd141c471e9dce2ead8203391461dc8cad2e226c10f9b9c5e8d907c0')

export PBR_VERSION=$pkgver

prepare() {
  cd pipenv-to-requirements-$pkgver
  patch -p1 -i ../$pkgname-pipenv-2022.10.9.patch
}

build() {
  cd pipenv-to-requirements-$pkgver
  python setup.py build
}

check() {
  cd pipenv-to-requirements-$pkgver
  # https://github.com/gsemet/pipenv-to-requirements/pull/26#issuecomment-1370418878
  pytest --ignore pipenv_to_requirements/test_parsing.py
}

package() {
  cd pipenv-to-requirements-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
