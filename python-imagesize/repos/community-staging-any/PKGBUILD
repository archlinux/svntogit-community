pkgbase=python-imagesize
pkgname=('python-imagesize' 'python2-imagesize')
pkgver=0.7.1
pkgrel=2

pkgdesc='Getting image size from png/jpeg/jpeg2000/gif file'
url='https://github.com/shibukawa/imagesize_py'
arch=('any')
license=('MIT')

makedepends=('python-setuptools' 'python2-setuptools')

source=("https://pypi.python.org/packages/53/72/6c6f1e787d9cab2cc733cf042f125abec07209a58308831c9f292504e826/imagesize-$pkgver.tar.gz")

md5sums=('976148283286a6ba5f69b0f81aef8052')

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
