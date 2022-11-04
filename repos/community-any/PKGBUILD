# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.1a0
pkgrel=2
pkgdesc="An RST directive for injecting a Towncrier-generated changelog draft containing fragments for the unreleased (next) project version"
url="https://github.com/sphinx-contrib/sphinxcontrib-towncrier"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'towncrier')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-setuptools-scm'
             'python-setuptools-scm-git-archive' 'python-wheel')
checkdepends=('python-pytest-xdist')
source=("https://github.com/sphinx-contrib/sphinxcontrib-towncrier/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('4aad34852b3d8b4bcb3603aeefce4fdb1b908baab358031639430c3c63fc3728817bfa8d5b71b79e6df79efc1a75ebde62089c3eed4956869d16133ce6657ad7')

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
