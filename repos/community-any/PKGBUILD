# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>
# Contributor: farwayer <farwayer@gmail.com>

pkgname=python-colour
_pyname=colour
pkgver=0.1.5
pkgrel=11
pkgdesc="Colour representations manipulation library (RGB, HSL, web, ...)"
arch=('any')
url="https://github.com/vaab/colour"
license=('BSD')
depends=('python')
makedepends=('python-setuptools' 'python-d2to1')
checkdepends=('python-nose')
source=("https://files.pythonhosted.org/packages/source/${_pyname:0:1}/${_pyname}/${_pyname}-${pkgver}.tar.gz")
sha256sums=('af20120fefd2afede8b001fbef2ea9da70ad7d49fafdb6489025dae8745c3aee')

build() {
  cd $_pyname-$pkgver
  python setup.py build
}

check() {
  cd $_pyname-$pkgver
  nosetests
}

package() {
  cd $_pyname-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
