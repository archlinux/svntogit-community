# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pygithub
pkgname=('python-pygithub' 'python2-pygithub')
pkgver=1.43.2
pkgrel=1
pkgdesc="Use the full Github API v3"
arch=('any')
license=('LGPL')
url="https://github.com/PyGithub/PyGithub"
makedepends=('python-setuptools' 'python2-setuptools' 'python-pyjwt' 'python2-pyjwt'
             'python-requests' 'python2-requests' 'python-deprecated' 'python2-deprecated')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/PyGithub/PyGithub/archive/v$pkgver.tar.gz")
sha512sums=('5d68caf552e479f0702c70ae71103ef10126447e4b972ac4365d819beaf01a12e7a1e141f0f899966c6092aabb8375e53f53ead78be99c1991b991815fc40441')

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
