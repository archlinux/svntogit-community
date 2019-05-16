# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-zipp
pkgname=(python-zipp python2-zipp)
pkgver=0.5.1
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('x86_64')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python2-pathlib2' 'python2-contextlib2' 'python2-unittest2')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('cfd68a66dd3bb53fe4312ba4310dafcbd3d121a73ca954a419c2d137f31e016c261d0bc7c9a20e4f602242113e0a90f1c1744e855aa5260f475b745e5eada658')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python setup.py build
  python2 setup.py build
}

check() {
  cd zipp-$pkgver
  python setup.py test
  python2 setup.py test
}

package_python-zipp() {
  depends=('python')

  cd zipp-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-zipp() {
  depends=('python2')

  cd zipp-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
