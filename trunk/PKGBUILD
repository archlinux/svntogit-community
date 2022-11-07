# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.1a1
pkgrel=1
pkgdesc="An RST directive for injecting a Towncrier-generated changelog draft containing fragments for the unreleased (next) project version"
url="https://github.com/sphinx-contrib/sphinxcontrib-towncrier"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'towncrier')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-setuptools-scm'
             'python-setuptools-scm-git-archive' 'python-wheel')
checkdepends=('python-pytest-xdist')
source=("https://github.com/sphinx-contrib/sphinxcontrib-towncrier/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('831fa4020277222126ba793e90a8eb0b9a8a3b0278292bf86b9d8458b14f343f09604b598f0b03381281cfe89706e5bbdd99fdd525cdae699b9a0cb3a0aa4722')

prepare() {
  cd sphinxcontrib-towncrier-$pkgver
  sed -i '/pytest_cov/d;/--cov/d' pytest.ini
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
