pkgbase=python-imagesize
pkgname=('python-imagesize' 'python2-imagesize')
pkgver=1.2.0
pkgrel=1

pkgdesc='Getting image size from png/jpeg/jpeg2000/gif file'
url='https://github.com/shibukawa/imagesize_py'
arch=('any')
license=('MIT')

makedepends=('python-setuptools' 'python2-setuptools')

source=("https://files.pythonhosted.org/packages/source/i/imagesize/imagesize-$pkgver.tar.gz")

sha256sums=('b1f6b5a4eab1f73479a50fb79fcf729514a900c341d8503d62a62dbc4127a2b1')

build() {
  cp -r imagesize-$pkgver imagesize-$pkgver-py2

  cd "$srcdir"/imagesize-$pkgver
  python setup.py build

  cd "$srcdir"/imagesize-$pkgver-py2
  python2 setup.py build
}

package_python-imagesize() {
  depends=('python')

  cd imagesize-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

package_python2-imagesize() {
  depends=('python2')

  cd imagesize-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
}
