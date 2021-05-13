# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=5.40
pkgrel=1
pkgdesc="Python bindings to the magic library"
arch=('any')
url='https://darwinsys.com/file/'
depends=('python')
makedepends=('python-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('3b70df75fa4c9050d55b1ffdc28e5f3c8b8ef7d4efd1a06bf53f113b676d81114a85aae56e0897d32b53716662d64ad18ab251ca8c92c6405c69eb758bb99afb')

package_python-magic() {
  cd "${srcdir}/file-${pkgver}/python"

  python setup.py install --root="${pkgdir}" --optimize=1

  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
