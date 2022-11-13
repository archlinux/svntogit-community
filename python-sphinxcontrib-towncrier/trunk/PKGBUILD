# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.1a3
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
sha512sums=('37276dfe7c662aa2cd1e69ec0008faec9b7126718cb3147b6f5a87d90b23be97272c327c16ce2a4829184fb1e7f58e6c5ed293d4b924a15d418f4e6275adf411')

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
