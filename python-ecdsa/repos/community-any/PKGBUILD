# Maintainer: Angel Velasquez <angvp@archlinux.org>
# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-ecdsa
pkgver=0.18.0
pkgrel=2
pkgdesc="Implementation of ECDSA in Python"
arch=('any')
url="https://github.com/tlsfuzzer/python-ecdsa"
license=('MIT')
depends=('python-six')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-hypothesis')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/e/ecdsa/ecdsa-$pkgver.tar.gz")
sha512sums=('f26dbeccd8e6ec832405d419b7244ca97b43a2811513493913a4f2f2fd1d2f453068fe0ba7b90b972f42a0d7b9834212fbd4d4559475cffeb1d80075fa954d78')

check() {
  cd ecdsa-$pkgver
  python -m pytest
}

package() {
  cd ecdsa-$pkgver
  python setup.py install --root="$pkgdir/" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
