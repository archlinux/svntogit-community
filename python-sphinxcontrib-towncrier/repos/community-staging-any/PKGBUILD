# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.2a0
pkgrel=5
pkgdesc="An RST directive for injecting a Towncrier-generated changelog draft containing fragments for the unreleased (next) project version"
url="https://github.com/sphinx-contrib/sphinxcontrib-towncrier"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'towncrier')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-pytest-xdist')
source=(
  "https://github.com/sphinx-contrib/sphinxcontrib-towncrier/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
  0001-Update-build-system-dependencies.patch
)
sha512sums=('3194136b8758b2881687af5a4fe56d1524fb6c0fe77745b25632895a6c7b6ed4a052d5cf000acabf9fb7c2ebce2e7e0a907d143d014d7be275f61547c0c76122'
            'e8c5f943e4ad8990a97a6aa8e493a1346cd9725a08c2b3e6ab0f3eb9371b9a63a55bad242060916f8a5ebfefe2a4c5c96b9a73291996fe3a4693c9b0920ca6b8')

prepare() {
  cd sphinxcontrib-towncrier-$pkgver
  # remove requirement for python-setuptools-scm-git-archive: https://github.com/sphinx-contrib/sphinxcontrib-towncrier/pull/80
  patch -Np1 -i ../0001-Update-build-system-dependencies.patch

  sed -i '/pytest_cov/d;/--cov/d' pytest.ini

  # Do not treat warnings as errors
  sed -i '/^  error$/d' pytest.ini
}

build() {
  cd sphinxcontrib-towncrier-$pkgver
  python -m build -nw
}

check() {
  cd sphinxcontrib-towncrier-$pkgver
  PYTHONPATH="$PWD"/src pytest
}

package() {
  cd sphinxcontrib-towncrier-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
