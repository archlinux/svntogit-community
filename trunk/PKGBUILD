# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

pkgbase=python-setuptools-scm
pkgname=(python-setuptools-scm python2-setuptools-scm)
pkgver=3.3.0
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata."
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'mercurial' 'git' 'python-pip' 'python2-pip')
source=("https://pypi.io/packages/source/s/setuptools_scm/setuptools_scm-$pkgver.tar.gz")
sha512sums=('e25be0e7efe56b5dcdaacf31ed512b3396285664a52a14a3d25d9ff4e2d6f3bb8e632d87b78d4ae323e0bbbfd16ac172a7d1b03a6837bf44a9753df1a4b92d0f')

prepare() {
  cp -a setuptools_scm-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/setuptools_scm-$pkgver
  python setup.py build
  python setup.py egg_info

  cd "$srcdir"/setuptools_scm-$pkgver-py2
  python2 setup.py build
  python2 setup.py egg_info
}

check() {
  # Hack entry points by installing it

  cd "$srcdir"/setuptools_scm-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.7/site-packages:$PYTHONPATH" py.test

  cd "$srcdir"/setuptools_scm-$pkgver-py2
  python2 setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python2.7/site-packages:$PYTHONPATH" py.test2
}

package_python-setuptools-scm() {
  depends=('python-setuptools')
  provides=('python-setuptools_scm')
  conflicts=('python-setuptools_scm')
  replaces=('python-setuptools_scm')

  cd "$srcdir"/setuptools_scm-$pkgver
  python setup.py install --root "$pkgdir"

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-setuptools-scm() {
  depends=('python2-setuptools')
  provides=('python2-setuptools_scm')
  conflicts=('python2-setuptools_scm')
  replaces=('python2-setuptools_scm')

  cd "$srcdir"/setuptools_scm-$pkgver-py2
  python2 setup.py install --root "$pkgdir"

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
