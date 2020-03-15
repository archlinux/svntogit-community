# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>

pkgname=python-magic
pkgver=5.38
pkgrel=1
pkgdesc="Python bindings to the magic library"
arch=('any')
url='https://darwinsys.com/file/'
depends=('python')
makedepends=('python-setuptools')
license=('custom')
source=("ftp://ftp.astron.com/pub/file/file-${pkgver}.tar.gz")
sha512sums=('9eeeba69cbc9f0c00a0bdf9eaf60c73a4a709e797068f109d85c1ef2a19c8b0e012ecd73714f03cbb1770dfa717e8a661ad746b644cc030cafbfb1f7aac35a40')

package_python-magic() {
  cd "${srcdir}/file-${pkgver}/python"

  python setup.py install --root="${pkgdir}" --optimize=1

  install -Dm0644 "${srcdir}/file-${pkgver}/COPYING" \
    "${pkgdir}/usr/share/licenses/${pkgname}/COPYING"
}
