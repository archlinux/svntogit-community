# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-zipp
pkgname=(python-zipp python2-zipp)
pkgver=0.6.0
pkgrel=3
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('x86_64')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python-more-itertools'
             'python2-more-itertools')
checkdepends=('python2-pathlib2' 'python2-contextlib2' 'python2-unittest2')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('9aef3b03a19d76cb72e1510d62a4edd536cbb176a4593154d6f98ecf020438249307ee5f8205f29e7f121acd61c105ca79a1ed48c66c6ba8799e2dbb3eecd75e')

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
  depends=('python-more-itertools')

  cd zipp-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-zipp() {
  depends=('python2-more-itertools')

  cd zipp-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
