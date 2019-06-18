# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgbase=python-colorama
pkgname=('python-colorama' 'python2-colorama')
pkgver=0.4.1
pkgrel=1
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-mock' 'python2-mock')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('006069859ca05ec8a6808860ca73ab541b246e6e6443b1bc8426973beaa5268660b48994f21edb6492fe97c4b9d29949b874b861ec200b1756d40e8abda8dee0')

prepare() {
  cp -a colorama-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/colorama-$pkgver
  python setup.py build

  cd "$srcdir"/colorama-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/colorama-$pkgver
  python -m unittest discover -p *_test.py || warning "Tests failed"

  cd "$srcdir"/colorama-$pkgver-py2
  python2 -m unittest discover -p *_test.py || warning "Tests failed"
}

package_python-colorama() {
  depends=('python')

  cd colorama-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}

package_python2-colorama() {
  depends=('python2')

  cd colorama-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}

# vim:set ts=2 sw=2 et:
