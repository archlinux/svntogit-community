# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

pkgbase=python-setuptools-scm
pkgname=(python-setuptools-scm python2-setuptools-scm)
pkgver=3.3.2
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata."
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'mercurial' 'git' 'python-pip' 'python2-pip')
source=("https://pypi.io/packages/source/s/setuptools_scm/setuptools_scm-$pkgver.tar.gz")
sha512sums=('a4f5acecac3f647f30b1685f3ab7171d291d0f3b12c4e0b8ef0086f37d0790b00103aad6e75e54c7774661237c23419a5997e9e632bf26f3db8ac413c8caeb75')

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
