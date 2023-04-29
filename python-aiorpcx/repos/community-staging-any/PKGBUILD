# Maintainer : Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: smmalis37

pkgname='python-aiorpcx'
pkgver=0.22.1
pkgrel=2
pkgdesc="A generic asyncio library implementation of RPC suitable for an application that is a client, server or both."
url="https://github.com/kyuupichan/aiorpcX/"
arch=('any')
license=('MIT')
depends=('python>=3.6' 'python-attrs')
makedepends=('python-setuptools' 'python-websockets')
source=("https://github.com/kyuupichan/aiorpcX/archive/${pkgver}.tar.gz")
sha256sums=('f72034c4854daf32d83c06ca940d39336908d55ad6a2fe17c039124d51b89430')


build() {
  cd "${srcdir}/aiorpcX-${pkgver}"
  python setup.py build
}

package() {
  cd "${srcdir}/aiorpcX-${pkgver}"
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -D -m644 LICENCE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
