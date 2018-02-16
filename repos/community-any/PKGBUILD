pkgbase=python-imagesize
pkgname=('python-imagesize' 'python2-imagesize')
pkgver=1.0.0
pkgrel=1

pkgdesc='Getting image size from png/jpeg/jpeg2000/gif file'
url='https://github.com/shibukawa/imagesize_py'
arch=('any')
license=('MIT')

makedepends=('python-setuptools' 'python2-setuptools')

source=("https://files.pythonhosted.org/packages/source/i/imagesize/imagesize-$pkgver.tar.gz")

md5sums=('9aa76df782f1df5b917794638b6bb6c2')

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
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-imagesize() {
  depends=('python2')

  cd imagesize-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
