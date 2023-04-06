# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Michael Schubert <mschu.dev at gmail>

pkgbase=python-pysocks
pkgname=(python-pysocks)
pkgver=1.7.1
_commit=f660e75d4844e64e4b162b0c01f8df8d866ee000
pkgrel=8
pkgdesc="SOCKS4, SOCKS5 or HTTP proxy (Anorov fork PySocks replaces socksipy)"
arch=('any')
license=('BSD')
url="https://github.com/Anorov/PySocks"
makedepends=('python-setuptools')
checkdepends=('lib32-glibc')
source=("$pkgbase-$_commit.tar.gz::https://github.com/Anorov/PySocks/archive/$_commit.tar.gz")
sha512sums=('d5db8d55603758cecd0e4974729df437febcfabe8a80dcbfe6132d0ce5a23caeccfefff01bf918cdbb9f26db4cb795d26ed1f3c536c415b496e4ac1bd43e9240')

prepare() {
  mv PySocks-{$_commit,$pkgver}
  cp -a PySocks-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/PySocks-$pkgver
  python setup.py build
}

# Tests disabled as it requires external services to run
# Fox: Removed depends. I didn't want to remove the code<3
check_disabled() {
  cd "$srcdir"/PySocks-$pkgver/test
  python sockstest.py

  ./mocks shutdown

  kill $_SOCKS4SERVER $_HTTPPROXY
}

package_python-pysocks() {
  depends=('python')
  provides=('python-socks')
  replaces=('python-socks')

  cd PySocks-$pkgver
  python setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
