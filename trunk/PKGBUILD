# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-zipp
pkgname=(python-zipp python2-zipp)
pkgver=0.3.3
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('x86_64')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-runner' 'python2-pytest-runner' 'python-pytest-flake8'
              'python2-pytest-flake8')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/$pkgver.tar.gz")
sha512sums=('b22e2a2d576ab3ec71cf0065875ce82c4020a7a490493bb007d51592bc7be957487af50f1e77a6a550eb0ebbfb621617f60e5ced559609687e22be98816843ac')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python setup.py build
  python2 setup.py build
}

check() {
  cd zipp-$pkgver
  python setup.py pytest
  python2 setup.py pytest
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
