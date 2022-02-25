# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.2.1a0
pkgrel=1
pkgdesc="An RST directive for injecting a Towncrier-generated changelog draft containing fragments for the unreleased (next) project version"
url="https://github.com/sphinx-contrib/sphinxcontrib-towncrier"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'towncrier')
makedepends=('python-setuptools')
checkdepends=('python-pytest-xdist')
source=("https://github.com/sphinx-contrib/sphinxcontrib-towncrier/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('58101532db51435e64e09746a09b5ad41ca903c1261d534c87ae82b7004d3da33ff33082f7acead55ab38d38117b4250df42e81d1371ab0f1e6ec9afaf860303')

build() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py build
}

check() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD"/src pytest
}

package() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
