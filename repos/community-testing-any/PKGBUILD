pkgname=python-imagesize
pkgver=1.2.0
pkgrel=4

pkgdesc='Getting image size from png/jpeg/jpeg2000/gif file'
url='https://github.com/shibukawa/imagesize_py'
arch=('any')
license=('MIT')

depends=('python')
makedepends=('python-setuptools')

source=("https://files.pythonhosted.org/packages/source/i/imagesize/imagesize-$pkgver.tar.gz")

sha256sums=('b1f6b5a4eab1f73479a50fb79fcf729514a900c341d8503d62a62dbc4127a2b1')

build() {
  cd "$srcdir"/imagesize-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/imagesize-$pkgver
  python -m unittest discover -v
}

package() {
  cd imagesize-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
