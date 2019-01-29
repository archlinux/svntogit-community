# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pygithub
pkgname=('python-pygithub' 'python2-pygithub')
pkgver=1.43.5
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
makedepends=('python-setuptools' 'python2-setuptools' 'python-pyjwt' 'python2-pyjwt'
             'python-requests' 'python2-requests' 'python-deprecated' 'python2-deprecated')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('703de65539c1e2af4462285d1788611d98a4052fcf223b54795da34679d1e327de8758d895d73b707f87f8a006171bc5c6b8182388ac6fde3808be8af6021dde')

prepare() {
  cp -a PyGithub-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/PyGithub-$pkgver
  python setup.py build

  cd "$srcdir"/PyGithub-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/PyGithub-$pkgver
  python setup.py test

  cd "$srcdir"/PyGithub-$pkgver-py2
  python2 setup.py test
}

package_python-pygithub() {
  depends=('python-pyjwt' 'python-requests' 'python-deprecated')

  cd PyGithub-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-pygithub() {
  depends=('python2-pyjwt' 'python2-requests' 'python2-deprecated')

  cd PyGithub-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
