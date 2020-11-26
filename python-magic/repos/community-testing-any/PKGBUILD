# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=5.39
pkgrel=3
pkgdesc="Python bindings to the magic library"
arch=('any')
url='https://darwinsys.com/file/'
depends=('python')
makedepends=('python-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('9cf1a7b769c56eb6f5b25c66ce85fa1300128396e445b2e53dbbd8951e5da973a7a07c4ef9f7ebd1fe945d47bdaf2cd9ef09bd2be6c217a0bcb907d9449835e6')

package_python-magic() {
  cd "${srcdir}/file-${pkgver}/python"

  python setup.py install --root="${pkgdir}" --optimize=1

  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
