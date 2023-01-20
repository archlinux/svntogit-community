# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-yarg
pkgver=0.1.9
pkgrel=8
pkgdesc="A semi hard Cornish cheese, also queries PyPI (PyPI client)"
url="https://github.com/kura/yarg"
license=('MIT')
arch=('any')
depends=('python-requests')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/kura/yarg/archive/$pkgver.tar.gz")
sha512sums=('1083608b0c2f84d15c27af9c9fbaf802e9f770518fc2c46bd6ba07d2123d4ad0a9ac7673a14714e579664ffef44667a21d1bec6417d9075c315749175bcd8fd9')

build() {
  cd yarg-$pkgver
  python setup.py build
}

check() {
  cd yarg-$pkgver
  python runtests.py
}

package() {
  cd yarg-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/

  local python_version=$(python -c 'import sys; print(".".join(map(str, sys.version_info[:2])))')
  mv "$pkgdir"/usr/lib/python${python_version}/site-packages/{,yarg/}tests
}
