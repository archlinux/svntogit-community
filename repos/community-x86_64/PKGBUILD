# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-zipp
pkgname=(python-zipp python2-zipp)
pkgver=2.0.0
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('x86_64')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python-more-itertools'
             'python2-more-itertools')
checkdepends=('python2-pathlib2' 'python2-contextlib2' 'python2-unittest2')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/jaraco/zipp/archive/v$pkgver.tar.gz")
sha512sums=('9bd8b4e14d051491dd0a67f6c61e128b7e699f57c25caabcbd093d7de11c3c621bfb76447cfce642a339a3a220ab4193b22ea44b98c963aba48a0b837bc669c9')

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
