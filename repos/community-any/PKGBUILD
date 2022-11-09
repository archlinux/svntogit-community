# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.1a2
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
sha512sums=('268bed3b475f0fa5f3546f2dfc5065b5de3c7f28b4f15d79ddad11620441403b4b1d22d249e75e08ea5543cf746949cd46639ed823c9f319d167a098f58fd991')

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
