# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

pkgname=python-imagesize
pkgver=1.4.1
pkgrel=1

pkgdesc='Analyzes JPEG/JPEG 2000/PNG/GIF/TIFF/SVG/Netpbm/WebP image headers and returns image size or DPI'
url='https://github.com/shibukawa/imagesize_py'
arch=('any')
license=('MIT')

depends=('python')
makedepends=('python-setuptools')

source=("https://files.pythonhosted.org/packages/source/i/imagesize/imagesize-$pkgver.tar.gz")

sha256sums=('69150444affb9cb0d5cc5a92b3676f0b2fb7cd9ae39e947a5e11a36b4497cd4a')

build() {
  cd imagesize-$pkgver
  python setup.py build
}

check() {
  cd imagesize-$pkgver
  python -m unittest discover -v
}

package() {
  cd imagesize-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE.rst
}
